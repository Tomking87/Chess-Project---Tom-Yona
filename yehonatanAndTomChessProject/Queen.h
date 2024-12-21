#pragma once
#include "ChessPiece.h"

class Queen : public ChessPiece
{
public:
    int move() override;
};