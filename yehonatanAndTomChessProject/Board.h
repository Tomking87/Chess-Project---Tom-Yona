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
	Board();
	~Board();
	Square getSquare() const; // get a squere at the board
	void setBoard(Square square, std::string position); // sets a specific Square at the board
	// take the algebretic notation and convert it into x and y cords in format: int xy
	int convertPositionToIntCords(std::string position);

};