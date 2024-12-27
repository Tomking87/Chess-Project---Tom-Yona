#pragma once
#include "ChessPiece.h"

class Rook : public ChessPiece
{
public:
	Rook(std::string position, char color, char type);
	~Rook();
	std::vector<std::string> move(const Board& chessBoard) override;
};