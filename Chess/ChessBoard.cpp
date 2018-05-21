#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
	Board.resize(8, vector<Chess_Squre>(8));
	ChessFactory::Factory(Board);
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