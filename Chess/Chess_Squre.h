#pragma once
#include"ChessPiece.h"
#include"ChessBoard.h"

#define	CLICKED			0b0001
#define UNCLICKED		0b0010
#define CLICKABLE		0b0100
#define UNCLICKABLE		0b1000

//Chess_Squre class mean one point of Chess Board
class Chess_Squre
{
	private:
		int State;
		int isClickable;
		ChessPiece * OnPiece;

	public:
		void Click(ChessBoard&);
};
