#pragma once
#include "ChessPiece.h"

class Knight : public ChessPiece
{
public:
    int move() override;
};