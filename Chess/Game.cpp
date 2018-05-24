#include "Game.h"

Game::Game(int GameType)
{
	this->GameType = GameType;
	this->Turn = WHITE;

	Board = new ChessBoard();
}

void Game::Action(int x, int y)
{
	Board->Click(x, y, this->Turn);

	this->Turn = !this->Turn;
}