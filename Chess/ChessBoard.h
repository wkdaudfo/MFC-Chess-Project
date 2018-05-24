#pragma once
#include<vector>
#include"Chess_Squre.h"
#include"ChessInitFactory.h"

using namespace std;

//ChessBoard implementation
class ChessBoard 
{
	private:
		vector<vector<Chess_Squre>> Board;
		Chess_Squre * Selected;

	public:
		
		//TODO: ChessBoard function have to include board initiation	
		ChessBoard();
		void GetBoard(vector<vector<Chess_Squre>>&);
		void GetBoard(Chess_Squre[X][Y]);
		void Click(int x, int y, int); //Cause Chess_Squre event
		void ClearState();
};
