#pragma once
#include "ChessPiece.h"

class King : public ChessPiece
{
public:
    King(std::string position, char color, char type);
    ~King();
    int move() override;
};