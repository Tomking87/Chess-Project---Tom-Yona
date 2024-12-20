#pragma once
#include "Square.h"
#include <string>
#define rowLength 8
#define colLength 8

class Board
{
private:
	Square _BoardGrid[rowLength][colLength];

public:
	Board();
	~Board();
	Square getBoard() const; // get a squere at the board
	void setBoard(Square square, std::string position); // sets a specific Square at the board
	// take the algebretic notation and convert it into x and y cords in format: int xy
	int convertPositionToIntCords(std::string position);

};