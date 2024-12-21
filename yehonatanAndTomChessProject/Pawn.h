#pragma once
#include "ChessPiece.h"

class Pawn : public ChessPiece
{
private:
    bool hasMoved;
public:
    bool getMovedStatus();
    int move() override;
    int eat();
};