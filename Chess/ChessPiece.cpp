#include "ChessPiece.h"

Pawn::Pawn ()
	: isFirstMove (true)
{}

void Pawn::PawnMove ()
{
	this->isFirstMove = false;
	return;
}

void Pawn::GetCandidate (vector<point>& p)
{

	if (this->isFirstMove) // 폰이 처음 움직일 때
	{
		p.push_back ({ 0,1 });

		p.push_back ({ 0,2 });
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
	}
	return;
}

void Queen::GetCandidate (vector<point>& p)
{
	//	point posible;
	for (int i = 1; i < 8; i++)
	{
		p.push_back ({ i, i });
		p.push_back ({ -i,-i });

		p.push_back ({ 0,i });
		p.push_back ({ 0,-i });

		p.push_back ({ i,0 });
		p.push_back ({ -i,0 });
	}
	return;
}

void King::GetCandidate (vector<point>& p)
{
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