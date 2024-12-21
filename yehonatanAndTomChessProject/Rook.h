#pragma once
#include "ChessPiece.h"

class Rook : public ChessPiece
{
public:
	Rook(std::string position, char color);
	~Rook();
	int move() override;
};