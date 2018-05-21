#pragma once
#include "ChessBoard.h"
#include "ChessMacro.h"

const int Board_Color[X][Y] =
{
	{B, B, B, B, B, B ,B, B},
	{B, B, B, B, B, B, B, B},
	{E, E, E, E, E, E, E, E},
	{E, E, E, E, E, E, E, E},
	{E, E, E, E, E, E, E, E},
	{E, E, E, E, E, E, E, E},
	{W, W, W, W, W, W, W, W},
	{W, W, W, W, W, W, W, W}
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