#pragma once
#include "ChessPiece.h"

class Queen : public ChessPiece
{
public:
    Queen(std::string position, char color, char type);
    ~Queen();
    std::vector<std::string> move(const Board& chessBoard) override;
};