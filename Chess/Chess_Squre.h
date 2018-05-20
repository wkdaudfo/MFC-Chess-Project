#pragma once
#include"ChessPiece.h"

#define	CLICKED		0b00
#define UNCLICKED	0b01
#define CLICKABLE	0b00
#define UNCLICKABLE 0b01

//Chess_Squre class mean one point of Chess Board
class Chess_Squre
{
	private:
		int State;
		int isClickable;
		ChessPiece * OnPiece;

	public:
		void Click();
};
