#include "Square.h"

Square::Square()
{
	this->_isEmpty = true;
	this->_piece = nullptr;
	this->_position = "";
}


Square::Square(bool isEmpty, ChessPiece* piece, std::string position)
{
	this->_isEmpty = isEmpty;
	this->_piece = piece;
	this->_position = position;
}

Square::~Square()
{

}

bool Square::getSquareStatus() const
{
	return this->_isEmpty;
}
void Square::setSquareStatus(bool squareStatus)
{
	this->_isEmpty = squareStatus;
}
ChessPiece* Square::getChessPieceAtSquare() const
{
	return this->_piece;
}
std::string Square::getSquarePosition() const
{
	return this->_position;
}
void Square::setPieceInSquare(ChessPiece* piece)
{
	this->_piece = piece;
}