#include <string>
#include "chessPiece.h"


ChessPiece::ChessPiece(std::string position, char color, char type)
{
    this->_Xposition = position[0]; -'0';
    this->_Yposition = position[1] - '0';
    this->_color = color;
    this->_type = type;
}

ChessPiece::~ChessPiece()
{

}

char ChessPiece::getChessPieceColor()
{
    return this->_color;
}

char ChessPiece::getChessPieceType()
{
    return this->_type;
}