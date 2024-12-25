#pragma once
#include "ChessPiece.h"

class ChessPiece;

class Bishop : public ChessPiece
{
public: 
    Bishop(std::string position, char color, char type);
    ~Bishop();
	std::vector<std::string> move(Board chessBoard) override;
};