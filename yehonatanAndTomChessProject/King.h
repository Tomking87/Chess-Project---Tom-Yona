#pragma once
#include "ChessPiece.h"

class King : public ChessPiece
{
public:
    King(std::string position, char color, char type);
    ~King();
    std::string* move(Board chessBoard) override;
};