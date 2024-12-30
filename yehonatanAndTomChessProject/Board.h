#pragma once
#include "Square.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include <vector>
#include <string>
#define rowLength 8
#define colLength 8

class Board
{
private:
	std::vector<std::vector<Square>> _BoardGrid;

public:
	/*
	Constructor that creates a new chess board
	Initializes an 8x8 grid of squares representing a chess board
	input: none
	output: none
	*/
	Board();

	/*
	Overloaded Constructor that is responsible for creating The Ficher Random Board
	input: none
	output: none
	*/
	Board(std::vector<char> shuffle);

	/*
	Destructor that cleans up the chess board and its components
	input: none
	output: none
	*/
	~Board();

	/*
	Returns a square from the specified position on the chess board
	input: int Yposition - the row number (0-7)
		  int Xposition - the column number (0-7)
	output: Square - the square object at the specified position
	*/
	Square getSquare(int Yposition, int Xposition) const;

	/*
	Places a square object at the specified position on the board
	input: Square mySquare - the square object to be placed
		  string position - the position on the board in format "YX" (Y and X are digits 0-7)
	output: none
	*/
	void setSquareInBoard(Square mySquare, std::string position);

	/*
	Updates the board state after a move is made
	Takes a move string representing the source and destination positions
	input: string moveString - represents the move in format "srcY srcX dstY dstX"
	output: none
	*/
	void updateBoard(std::string moveString);
};