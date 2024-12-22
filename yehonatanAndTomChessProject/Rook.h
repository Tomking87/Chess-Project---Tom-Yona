#pragma once
#include "ChessPiece.h"

class Rook : public ChessPiece
{
public:
	Rook(std::string position, char color, char type);
	~Rook();
	std::string* move(Board chessBoard) override;
};