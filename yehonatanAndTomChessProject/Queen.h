#pragma once
#include "ChessPiece.h"

class Queen : public ChessPiece
{
public:
    Queen(std::string position, char color, char type);
    ~Queen();
    std::string* move(Board chessBoard) override;
};