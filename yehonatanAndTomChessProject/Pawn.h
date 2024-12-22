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
    std::string* move() override;
    int eat();
};