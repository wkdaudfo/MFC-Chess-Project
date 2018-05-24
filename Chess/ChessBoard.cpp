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
				Board[x][y].Click(candidate);

				Selected = &Board[x][y];

				for (auto point : candidate)
				{
					if (x + point.x >= 0 && x + point.x < 8 && y + point.y >= 0 && y + point.y < 0)
					{
						Board[x + point.x][y + point.y].SetState(CLICKABLE);
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
		}
	}
}