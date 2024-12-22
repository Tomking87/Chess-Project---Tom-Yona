#include "Pawn.h"
#include "ChessPiece.h"
using namespace std;


Pawn::Pawn(std::string position, char color, bool hasMoved, char type) : ChessPiece(position, color, type)
{
	this->_hasMoved = hasMoved;
}

Pawn::~Pawn()
{
	// already Implemented in chessPiece
}

string* Pawn::move()
{
    string* myStr = new string[1];
    // Need to implement
    return myStr;
}