#pragma once
#include "ChessPiece.h"

class King : public ChessPiece
{
public:
	/*
	Constructor for the King class. Initializes the king with its position, color, and type.
	input: position (string) - initial position (e.g., "e1"),
		   color (char) - 'W' for White or 'B' for Black,
		   type (char) - 'K' for King
	output: none
	*/
	King(std::string position, char color, char type);

	/*
	Destructor for the King class.
	input: none
	output: none
	*/
	~King();

	/*
	Calculates all valid moves for the king based on the current state of the chessboard.
	input: chessBoard (const Board&) - the current state of the chessboard
	output: std::vector<std::string> - a list of valid moves for the king
	*/
	std::vector<std::string> move(const Board& chessBoard) override;
};
