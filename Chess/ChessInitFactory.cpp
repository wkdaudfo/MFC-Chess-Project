#include "ChessInitFactory.h"

void ChessFactory::Factory(vector<vector<Chess_Squre>>& Board)
{
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			switch (Board_Piece[i][j])
			{
			case P:
				Board[i][j] = Chess_Squre(new Pawn(Board_Color[i][j]), CLICKABLE);
			case R:
				Board[i][j] = Chess_Squre(new Rook(Board_Color[i][j]), CLICKABLE);
			case KN:
				Board[i][j] = Chess_Squre(new Knight(Board_Color[i][j]), CLICKABLE);
			case B:
				Board[i][j] = Chess_Squre(new Bishop(Board_Color[i][j]), CLICKABLE);
			case Q:
				Board[i][j] = Chess_Squre(new Queen(Board_Color[i][j]), CLICKABLE);
			case K:
				Board[i][j] = Chess_Squre(new King(Board_Color[i][j]), CLICKABLE);
			default:
				Board[i][j] = Chess_Squre(new EmptyPiece(Board_Color[i][j]), UNCLICKABLE);
			}
		}
	}
}