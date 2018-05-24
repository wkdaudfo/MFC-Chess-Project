#include "ChessPiece.h"

ChessPiece::ChessPiece(int Color)
{
	this->Color = Color;
}

Pawn::Pawn(int Color) :
	isFirstMove(true),
	ChessPiece(Color)
{}

Rook::Rook(int Color) :
	ChessPiece(Color)
{}

Bishop::Bishop(int Color) :
	ChessPiece(Color)
{}

Knight::Knight(int Color) :
	ChessPiece(Color)
{}

Queen::Queen(int Color) :
	ChessPiece(Color)
{}

King::King(int Color) :
	ChessPiece(Color)
{}

EmptyPiece::EmptyPiece(int Color = EMPTY) :
	ChessPiece(Color)
{}


void Pawn::GetCandidate (vector<point>& p)
{

	if (this->isFirstMove) // 폰이 처음 움직일 때
	{
		p.push_back ({ 0,1 });

		p.push_back ({ 0,2 });

		p.push_back({ 1, 1 });
		p.push_back({ -1, 1 });
	}
	else
	{
		p.push_back ({ 0,1 });

		p.push_back ({ 1,1 });

		p.push_back ({ -1,1 });
	}
	return;
}

void Knight::GetCandidate (vector<point> &p)
{
	p.push_back ({ 1,2 });
	p.push_back ({ -1,2 });

	p.push_back ({ 2,1 });
	p.push_back ({ -2,1 });

	p.push_back ({ 1,-2 });
	p.push_back ({ -1,-2 });

	p.push_back ({ 2,-1 });
	p.push_back ({ -2,-1 });

	return;
}

void Rook::GetCandidate (vector<point>& p)
{
	for (int i = 1; i < 8; i++)
	{
		p.push_back ({ 0,i });
		p.push_back ({ 0,-i });
	}

	for (int i = 1; i < 8; i++)
	{
		p.push_back ({ i,0 });
		p.push_back ({ -i,0 });
	}
	return;
}

void Bishop::GetCandidate (vector<point>& p)
{
	for (int i = 1; i < 8; i++)
	{
		p.push_back ({ i, i });
		p.push_back ({ -i,-i });

		p.push_back({ i, -i });
		p.push_back({ -i, i });
	}
	return;
}

void Queen::GetCandidate (vector<point>& p)
{
	//	point posible;
	Bishop b(EMPTY);
	Rook r(EMPTY);

	b.GetCandidate(p);
	r.GetCandidate(p);
	return;
}

void King::GetCandidate (vector<point>& p)
{
	//TO ADD The state of castlingc
	p.push_back ({ 0,1 });
	p.push_back ({ 0,-1 });

	p.push_back ({ 1,0 });
	p.push_back ({ -1,0 });

	p.push_back ({ 1,1 });
	p.push_back ({ -1,-1 });
	p.push_back ({ 1,-1 });
	p.push_back ({ -1,1 });

	return;
}

void EmptyPiece::GetCandidate (vector<point>& p)
{
	return;
}

void Pawn::Move()
{
	//TODO When Pawn arives end of board
	this->isFirstMove = false;
	return;
}

void Rook::Move()
{
	//TODO
	return;
}

void Bishop::Move()
{
	//TODO
	return;
}

void Knight::Move()
{
	//TODO
	return;
}

void Queen::Move()
{
	//TODO
	return;
}

void King::Move()
{
	//TODO Check if it is the statement of check
	return;
}

void EmptyPiece::Move()
{
	//TODO
	return;
}

int Pawn::GetType(int& color)
{
	color = this->Color;
	return P;
}

int Rook::GetType(int& color)
{
	color = this->Color;
	return R;
}

int Knight::GetType(int& color)
{
	color = this->Color;
	return KN;
}

int Bishop::GetType(int& color)
{
	color = this->Color;
	return B;
}

int Queen::GetType(int& color)
{
	color = this->Color;
	return Q;
}

int King::GetType(int& color)
{
	color = this->Color;
	return K;
}

int EmptyPiece::GetType(int& color)
{
	color = EMPTY;
	return EP;
}