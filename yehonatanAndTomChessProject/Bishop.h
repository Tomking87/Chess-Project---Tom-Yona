#pragma once
#include "ChessPiece.h"

class Bishop : public ChessPiece
{
public:
    Bishop(std::string position, char color, char type);
    ~Bishop();
    int move() override;
};