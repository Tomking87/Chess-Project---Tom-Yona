#pragma once
#include "ChessPiece.h"

class Pawn : public ChessPiece
{
private:
    bool _hasMoved;
public:
    Pawn(std::string position, char color, bool hasMoved);
    ~Pawn();
    bool getMovedStatus();
    int move() override;
    int eat();
};