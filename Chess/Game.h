#pragma once
#include"ChessBoard.h"
#include"ChessPlayer.h"

#define SOLO		0b00
#define	NETWORK		0b01
#define AI			0b10

#define WHITE		0
#define BLACK		1
//Game Information
//ChessBoard of this game
//GameType (Solo 1 vs 1, Netword, AI)
//Whose turn
class Game
{
	private:
		ChessBoard Board;
		int GameType;
		bool Turn;
};