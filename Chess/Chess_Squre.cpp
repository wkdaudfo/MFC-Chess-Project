#include "Chess_Squre.h"

Chess_Squre::Chess_Squre(ChessPiece* Piece, int State)
{
	this->OnPiece = Piece;
	this->State = State;
}