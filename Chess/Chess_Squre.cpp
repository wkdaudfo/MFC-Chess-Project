//#include "stdafx.h"
#include "Chess_Squre.h"

/*
Chess_Squre::Chess_Squre()
{}
*/

Chess_Squre::Chess_Squre(ChessPiece* Piece, int State)
{
	this->OnPiece = Piece;
	this->State = State;
}

int Chess_Squre::Click(vector<point>& Candidate, int& Straight)
{
	OnPiece->GetCandidate(Candidate, Straight);
	return true;
}

ChessPiece * Chess_Squre::Click(void*)
{
	return OnPiece;
}

int Chess_Squre::GetState()
{
	return this->State;
}

void Chess_Squre::SetState(int State)
{
	this->State = State;
}

int Chess_Squre::GetPiece(ChessPiece* ptr, int& Color)
{
	int color;
	int type = OnPiece->GetType(color);
	ptr = OnPiece;
	Color = color;
	return type;
}

void Chess_Squre::SetPiece(ChessPiece* ptr)
{
	OnPiece = ptr;
	return;
}
