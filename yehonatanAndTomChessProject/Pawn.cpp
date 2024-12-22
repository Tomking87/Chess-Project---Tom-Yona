#include "Pawn.h"
#include "ChessPiece.h"


Pawn::Pawn(std::string position, char color, bool hasMoved, char type) : ChessPiece(position, color, type)
{
	this->_hasMoved = hasMoved;
}

Pawn::~Pawn()
{
	// already Implemented in chessPiece
}

int Pawn::move()
{
	//Need to implement
	return 0;
}