#pragma once
#include "ChessBoard.h"
#include "ChessMacro.h"

class Chess_Squre;

const int Board_Color[X][Y] =
{
	{BLACK, BLACK, BLACK, BLACK, BLACK, BLACK ,BLACK, BLACK},
	{BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK},
	{E, E, E, E, E, E, E, E},
	{E, E, E, E, E, E, E, E},
	{E, E, E, E, E, E, E, E},
	{E, E, E, E, E, E, E, E},
	{WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
	{WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE}
};

const int Board_Piece[X][Y] =
{
	{R, KN, B, K, Q, B, KN, R},
	{P, P, P, P, P, P, P, P},
	{E, E, E, E, E, E, E, E},
	{E, E, E, E, E, E, E, E},
	{E, E, E, E, E, E, E, E},
	{E, E, E, E, E, E, E, E},
	{P, P, P, P, P, P, P, P},
	{R, KN, B, K, Q,  B, KN, R}
};

 class ChessFactory
 {
	public:
		static void Factory(vector<vector<Chess_Squre>>&);
 };