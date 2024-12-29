#pragma once
#include "ChessPiece.h"

class Bishop : public ChessPiece
{
public:
	/*
	Constructor for the Bishop class. Initializes the bishop with its position, color, and type.
	input: position (string) - initial position (e.g., "c1"),
		   color (char) - 'W' for White or 'B' for Black,
		   type (char) - 'B' for Bishop
	output: none
	*/
	Bishop(std::string position, char color, char type);

	/*
	Destructor for the Bishop class.
	input: none
	output: none
	*/
	~Bishop();

	/*
	Calculates all valid moves for the bishop based on the current state of the chessboard.
	input: chessBoard (const Board&) - the current state of the chessboard
	output: std::vector<std::string> - a list of valid moves for the bishop
	*/
	std::vector<std::string> move(const Board& chessBoard) override;
};
