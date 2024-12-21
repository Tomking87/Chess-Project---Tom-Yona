#pragma once
#include "ChessPiece.h"

class King : public ChessPiece
{
public:
    int move() override;
};