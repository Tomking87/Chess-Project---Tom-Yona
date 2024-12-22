#pragma once
#include "ChessPiece.h"

class Knight : public ChessPiece
{
public:
    Knight(std::string position, char color, char type);
    ~Knight();
    std::string* move(Board chessBoard) override;
};