#pragma once
#include "ChessPiece.h"

class Bishop : public ChessPiece
{
public:
    Bishop(std::string position, char color);
    ~Bishop();
    int move() override;
};