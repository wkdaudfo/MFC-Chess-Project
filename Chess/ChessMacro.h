#pragma once

//Player Color
#define WHITE					0
#define BLACK					1
#define EMPTY					2

//State
//#define	CLICKED					0b0001
//#define UNCLICKED				0b0010
#define CLICKABLE				true
#define UNCLICKABLE				false

//Chess Board Limit
#define X						8
#define Y						8

//Empty
#define E						EMPTY

//Chess Piece
#define P						0
#define R						1
#define KN						2
#define B						3
#define Q						4
#define K						5
#define EP						6

//Check if it is CHECK
#define CHECK					true
#define NOTCHECK				false

//Command when click Board
#define SWAPORKILL				0
#define SHOWCANDIDATE			1
#define NOTHING					2

//State of board
#define PIECECHOSEN				true
#define NOTHINGCHOSEN			false