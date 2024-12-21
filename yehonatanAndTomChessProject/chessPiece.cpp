#include <string>
#include "chessPiece.h"


ChessPiece::ChessPiece(std::string position, char color)
{
    this->_Xposition = position[0]; -'0';
    this->_Yposition = position[1] - '0';
    this->_color = color;
}

char ChessPiece::getChessPieceColor()
{
    return this->_color;
}