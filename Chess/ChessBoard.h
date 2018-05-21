#pragma once
#include<vector>
#include"Chess_Squre.h"

using namespace std;

#define X		8
#define Y		8

//ChessBoard implementation
class ChessBoard 
{
	private:
		vector<vector<Chess_Squre>> Board;
	public:
		
		//TODO: ChessBoard function have to include board initiation	
		ChessBoard();
		ChessBoard GetBoard();
		Click(int x, int y);
};
