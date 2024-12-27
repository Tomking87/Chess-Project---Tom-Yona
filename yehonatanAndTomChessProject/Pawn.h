#pragma once
#include "ChessPiece.h"

class Pawn : public ChessPiece
{
private:
    bool _hasMoved;
public:
    Pawn(std::string position, char color, bool hasMoved, char type);
    ~Pawn();
    bool getMovedStatus();
    std::vector<std::string> move(const Board& chessBoard) override;
    int eat();
};