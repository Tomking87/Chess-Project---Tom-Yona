#include "ChessPiece.h"

ChessPiece::ChessPiece(int position, char color)
{
	this->_color = color;
	this->_position = position;
}

void ChessPiece::checkForSelfChecks()
{
	//complete
}
void ChessPiece::checkForOpponentChecks()
{
	//complete
}