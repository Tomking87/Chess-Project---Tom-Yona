#include <string>
#include "chessPiece.h"


ChessPiece::ChessPiece(std::string position, char color, char type)
{
    this->_Xposition = position[1] - '0';
    this->_Yposition = position[0] - '0';
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

std::string ChessPiece::getCords()
{
    std::string cords = "";
    cords = std::to_string(this->_Yposition);
    cords += std::to_string(this->_Xposition);

    return cords;
}

void ChessPiece::setCords(int Ypos, int Xpos)
{
    this->_Xposition = Xpos;
    this->_Yposition = Ypos;
}