#pragma once
#include "ChessPiece.h"

class Knight : public ChessPiece
{
public:
    Knight(std::string position, char color);
    ~Knight();
    int move() override;
};