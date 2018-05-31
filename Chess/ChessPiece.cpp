#include "ChessPiece.h"

ChessPiece::ChessPiece(int Color)
{
	this->Color = Color;
}

Pawn::Pawn(int Color) :
	isFirstMove(true),
	ChessPiece(Color)
{
	this->Straight = 2;
}

Rook::Rook(int Color) :
	ChessPiece(Color)
{
	this->Straight = 8;
}

Bishop::Bishop(int Color) :
	ChessPiece(Color)
{
	this->Straight = 8;
}

Knight::Knight(int Color) :
	ChessPiece(Color)
{
	this->Straight = 1;
}

Queen::Queen(int Color) :
	ChessPiece(Color)
{
	this->Straight = 8;
}

King::King(int Color) :
	ChessPiece(Color)
{
	this->Straight = 1;
}

 EmptyPiece::EmptyPiece(int Color) :
	ChessPiece(Color)
{}


void Pawn::GetCandidate (vector<point>& p, int& Straight)
{

	p.push_back({ 0, 1 });

	//대각선에 적이 있을 시 예외처리
	return;
}

void Knight::GetCandidate (vector<point> &p, int& Straight)
{
	p.push_back ({ 1,2 });
	p.push_back ({ -1,2 });

	p.push_back ({ 2,1 });
	p.push_back ({ -2,1 });

	p.push_back ({ 1,-2 });
	p.push_back ({ -1,-2 });

	p.push_back ({ 2,-1 });
	p.push_back ({ -2,-1 });

	//얘는 그대로

	return;
}

void Rook::GetCandidate (vector<point>& p, int& Straight)
{
	p.push_back({ 0, 1 });
	p.push_back({ 0, -1 });
	
	p.push_back({ 1, 0 });
	p.push_back({ -1, 0 });
	return;
}

void Bishop::GetCandidate (vector<point>& p, int& Straight)
{
	p.push_back({ 1, 1 });
	p.push_back({ -1, -1 });

	p.push_back({ 1, -1 });
	p.push_back({ -1, 1 });
	return;
}

void Queen::GetCandidate (vector<point>& p, int& Straight)
{
	//	point posible;
	int temp;
	Bishop b(EMPTY);
	Rook r(EMPTY);

	b.GetCandidate(p, temp);
	r.GetCandidate(p, temp);
	return;
}

void King::GetCandidate (vector<point>& p, int& Straight)
{
	//TO ADD The state of castlingc
	int temp;
	Queen q(EMPTY);

	q.GetCandidate(p, temp);

	return;
}

void EmptyPiece::GetCandidate (vector<point>& p, int& Straight)
{
	return;
}

void Pawn::Move()
{
	//TODO When Pawn arives end of board
	this->isFirstMove = false;
	this->Straight = 1;
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