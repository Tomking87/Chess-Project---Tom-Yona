#pragma once
#include "ChessPiece.h"

class Knight : public ChessPiece
{
public:
	/*
	Constructor for the Knight class. Initializes the knight with its position, color, and type.
	input: position (string) - initial position (e.g., "b1"),
		   color (char) - 'W' for White or 'B' for Black,
		   type (char) - 'N' for Knight
	output: none
	*/
	Knight(std::string position, char color, char type);

	/*
	Destructor for the Knight class.
	input: none
	output: none
	*/
	~Knight();

	/*
	Calculates all valid moves for the knight based on the current state of the chessboard.
	input: chessBoard (const Board&) - the current state of the chessboard
	output: std::vector<std::string> - a list of valid moves for the knight
	*/
	std::vector<std::string> move(const Board& chessBoard) override;
};
