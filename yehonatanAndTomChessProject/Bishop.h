#pragma once
#include "ChessPiece.h"

class Bishop : public ChessPiece
{
public:
    int move() override;
};