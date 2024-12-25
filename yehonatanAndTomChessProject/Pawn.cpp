#include "Pawn.h"
#include "Board.h"

using namespace std;


Pawn::Pawn(std::string position, char color, bool hasMoved, char type) : ChessPiece(position, color, type)
{
	this->_hasMoved = hasMoved;
}

Pawn::~Pawn()
{
	// already Implemented in chessPiece
}

std::vector<std::string> Pawn::move(Board chessBoard)
{
    std::vector<std::string> validMoves;
    // Need to implement
    return validMoves;
}