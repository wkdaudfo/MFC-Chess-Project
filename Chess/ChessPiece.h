#pragma once
#include<vector>

#include "ChessMacro.h"

using namespace std;

struct point {
	int x, y;
};

//ChessPiece Abstract Class
//Interface of ChessPiece
//Push moveable point count to argument
class ChessPiece
{
	protected:
		int Color;

	public:
		ChessPiece(int Color);
		virtual void GetCandidate(vector<point>&) = 0;
		virtual int GetType(int&) = 0;
		/* MUST CALL THIS PROCEDURE WHEN CHESS PIECE MOVE*/
		virtual void Move() = 0;
};

//Pawn can move y + 1 or y + 2(First Move)

class Pawn : public ChessPiece
{
	private:
		bool isFirstMove;
	public:
		Pawn (int Color);
		virtual void Move();
		virtual void GetCandidate (vector<point>&);
		virtual int GetType(int&);
};

//Rook can move x +- (1 ~ 7) or y +- (1 ~ 7)
class Rook : public ChessPiece
{
	public:
		Rook(int Color);
		virtual void Move();
		virtual void GetCandidate (vector<point>&);
		virtual int GetType(int&);
};

//Knight can move (x +- 2, y +- 1) or (x +- 1, y +- 2)
class Knight : public ChessPiece
{
	public:
		Knight(int Color);
		virtual void Move();
		virtual void GetCandidate (vector<point>&);
		virtual int GetType(int&);
};

//Bishop can move (x, y +- 7)
class Bishop : public ChessPiece
{
	public:
		Bishop(int Color);
		virtual void Move();
		virtual void GetCandidate (vector<point>&);
		virtual int GetType(int&);
};

//Queen can move Bishop + Rook
class Queen : public ChessPiece
{
	public:
		Queen(int Color);
		virtual void Move();
		virtual void GetCandidate (vector<point>&);
		virtual int GetType(int&);
};

//King can move (x +- 1) or (y +- 1) or (x +- 1, y +- 1)
class King : public ChessPiece
{
	public:
		King(int Color);
		virtual void Move();
		virtual void GetCandidate (vector<point>&);
		virtual int GetType(int&);
};

//EmptyPiece only can move by action
class EmptyPiece : public ChessPiece
{
	public:
		EmptyPiece(int Color = EMPTY);
		virtual void Move();
		virtual void GetCandidate (vector<point>&);
		virtual int GetType(int&);
};