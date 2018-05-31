#pragma once
#include"ChessPiece.h"
#include"ChessBoard.h"
#include"ChessMacro.h"

//Chess_Squre class mean one point of Chess Board
class Chess_Squre
{
	private:
		int State;
		ChessPiece * OnPiece;
		
	public:
		Chess_Squre() {}
		Chess_Squre(ChessPiece*, int State);
		~Chess_Squre() {}
		int Click(vector<point>&, int&);
		ChessPiece * Click(void*);
		int GetState();
		int GetPiece(ChessPiece*, int&);
		void SetPiece(ChessPiece *);
		void SetState(int State);
};
