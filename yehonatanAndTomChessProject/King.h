#pragma once
#include "ChessPiece.h"

class King : public ChessPiece
{
public:
    King(std::string position, char color, char type);
    ~King();
    std::vector<std::string> move(const Board& chessBoard) override;
};