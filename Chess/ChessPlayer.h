#pragma once
#include"ChessPiece.h"

//Player Information
//Color(Black or White)
//Dead Chess Piece
//Is it check?
class Player
{
	private:
		bool Check;
		vector<ChessPiece> DeadPiece; //All Empty Piece
		bool Color;
};