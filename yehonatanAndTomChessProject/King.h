#pragma once
#include "ChessPiece.h"

class King : public ChessPiece
{
public:
    King(std::string position, char color);
    ~King();
    int move() override;
};