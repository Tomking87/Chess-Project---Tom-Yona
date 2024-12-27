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
	Square getSquare(int Yposition, int Xposition) const; // get a squere at the board
	void setSquareInBoard(Square mySquare, std::string position); // sets a specific Square at the board
	void updateBoard(std::string moveString);

};