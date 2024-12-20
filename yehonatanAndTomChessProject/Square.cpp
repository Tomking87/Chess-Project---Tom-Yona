#include "Square.h"

Square::Square(bool isEmpty, ChessPiece* piece, int position)
{
	this->_isEmpty = isEmpty;
	this->_piece = piece;
	this->_position = position;
}