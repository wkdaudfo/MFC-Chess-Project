#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
	Board.resize(8, vector<Chess_Squre>(8));
	ChessFactory::Factory(Board);
	Selected = nullptr;
}

void ChessBoard::GetBoard(vector<vector<Chess_Squre>>& Board)
{
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			Board[i][j] = this->Board[i][j];
		}
	}
}

void ChessBoard::GetBoard(Chess_Squre Board[X][Y])
{
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			Board[i][j] = this->Board[i][j];
		}
	}
}

void ChessBoard::Click(int x, int y, int player_color)
{
	if (Selected == nullptr)
	{
		if (Board[x][y].GetState == CLICKABLE)
		{
			int piece_color;
			Board[x][y].GetPiece(nullptr, piece_color);
			if (piece_color == player_color)
			{
				vector<point> candidate;
				int Straight;
				int th;

				Board[x][y].Click(candidate, Straight);
				int PieceType = Board[x][y].GetPiece(nullptr, th);

				Selected = &Board[x][y];

				this->AllUnClick();

				for (auto point : candidate)
				{
					if (PieceType != P)
					{
						for (int i = 1; i <= Straight; i++)
						{
							int PieceColor;

							if (x + point.x * i < 0 || x + point.x * i > X || y + point.y * i < 0 || y + point.y * i > Y)
								break;

							Board[x + point.x * i][y + point.y * i].GetPiece(nullptr, PieceColor);

							if (PieceColor == EMPTY)
							{
								Board[x + point.x*i][y + point.y*i].SetState(CLICKABLE);
								continue;
							}

							else if (PieceColor != player_color)
							{
								Board[x + point.x*i][y + point.y*i].SetState(CLICKABLE);
								break;
							}

							else
								break;
						}
					}

					else
					{
						int BWP = 1;
						int PieceColor;
						if (player_color == BLACK)
							BWP = -1;

						for (int i = 1; i <= Straight; i++)
						{
							if (x + point.x * i * BWP < 0 || x + point.x * i * BWP > X || y + point.y * i * BWP < 0 || y + point.y * i * BWP > Y)
								break;

							Board[x + point.x * i * BWP][y + point.y * i * BWP].GetPiece(nullptr, PieceColor);

							if (PieceColor == EMPTY)
							{
								Board[x + point.x * i * BWP][y + point.y * i * BWP].SetState(CLICKABLE);
								continue;
							}

							else
								break;
						}

						Board[x + 1][y + BWP].GetPiece(nullptr, PieceColor);

						if (PieceColor != EMPTY && PieceColor != player_color)
							Board[x + 1][y + BWP].SetState(CLICKABLE);

						Board[x - 1][y + BWP].GetPiece(nullptr, PieceColor);

						if (PieceColor != EMPTY && PieceColor != player_color)
							Board[x - 1][y + BWP].SetState(CLICKABLE);
					}
				}
			}
		}
	}

	else
	{
		if (Board[x][y].GetState == UNCLICKABLE)
		{
			Selected = nullptr;
			this->ClearState();
		}

		else
		{
			ChessPiece * second;
			int PickColor;
			int SelectedColor;

			int type = Board[x][y].GetPiece(second, PickColor);

			ChessPiece * first;
			Selected->GetPiece(first, SelectedColor);

			if (type == EP)
			{
				ChessPiece * temp = second;
				Board[x][y].SetPiece(first);
				Selected->SetPiece(temp);
			}

			else if(PickColor != SelectedColor)
			{
				Board[x][y].SetPiece(first);
				Selected->SetPiece(new EmptyPiece());
			}

			else
			{
				this->ClearState();
			}
			first->Move();
			ClearState();
			Selected = nullptr;
		}
	}
}

void ChessBoard::ClearState()
{
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			int color;
			int type = Board[i][j].GetPiece(nullptr, color);

			if (type == EP)
			{
				Board[i][j].SetState(UNCLICKABLE);
			}
			else
			{
				Board[i][j].SetState(CLICKABLE);
			}
		}
	}
}

void ChessBoard::AllUnClick()
{
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			Board[i][j].SetState(UNCLICKABLE);
		}
	}
}