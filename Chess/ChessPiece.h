#pragma once
#include<vector>

using namespace std;

struct point {
	int x, y;
};

//ChessPiece Abstract Class
//Interface of ChessPiece
//Push moveable point count to argument
class ChessPiece 
{
	public:
		virtual void GetCandidate(vector<point>&) = 0;
};

//Pawn can move y + 1 or y + 2(First Move)
class Pawn : public ChessPiece
{
	private:
		bool isFirstMove;
	public:
		Pawn()
			: isFirstMove(true)
		{}
		void GetCandiate(vector<point>&);
};

//Rook can move x +- (1 ~ 7) or y +- (1 ~ 7)
class Rook : public ChessPiece
{
	public:
		void GetCandidate(vector<point>&);
};

//Knight can move (x +- 2, y +- 1) or (x +- 1, y +- 2)
class Knight : public ChessPiece
{
	public:
		void GetCandidate(vector<point>&);
};

//Bishop can move (x, y +- 7)
class Bishop : public ChessPiece
{
	public:
		void GetCandidate(vector<point>&);
};

//Queen can move Bishop + Rook
class Queen : public ChessPiece
{
	public:
		void GetCandidate(vector<point>&);
};

//King can move (x +- 1) or (y +- 1) or (x +- 1, y +- 1)
class King : public ChessPiece
{
	public:
		void GetCandidate(vector<point>&);
};

//EmptyPiece only can move by action
class EmptyPiece : public ChessPiece
{
	public:
		void GetCandidate(vector<point>&);
};