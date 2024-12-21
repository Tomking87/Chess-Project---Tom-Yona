#pragma once
#include "ChessPiece.h"

class Queen : public ChessPiece
{
public:
    Queen(std::string position, char color);
    ~Queen();
    int move() override;
};