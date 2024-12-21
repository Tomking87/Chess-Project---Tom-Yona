#include "Pawn.h"
#include "ChessPiece.h"


Pawn::Pawn(std::string position, char color, bool hasMoved) : ChessPiece(position, color)
{
	this->_hasMoved = hasMoved;
}

Pawn::~Pawn()
{
	// already Implemented in chessPiece
}