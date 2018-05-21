#pragma once
#include"ChessPiece.h"

#define CHECK			TRUE
#define NOTCHECK		FALSE

#define WHITE			0
#define BLACK			1

//Player Information
//Color(Black or White)
//Dead Chess Piece
//Is it check?
class Player
{
	private:
		bool Check;
		vector<ChessPiece> DeadPiece;
		bool Color;
};