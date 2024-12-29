#pragma once
#include "ChessPiece.h"

class Pawn : public ChessPiece
{
private:
	bool _hasMoved;

public:
	/*
	Constructor for the Pawn class. Initializes the pawn with its position, color, moved status, and type.
	input: position (string) - initial position (e.g., "e2"),
		   color (char) - 'W' for White or 'B' for Black,
		   hasMoved (bool) - true if the pawn has already moved, false otherwise,
		   type (char) - 'P' for Pawn
	output: none
	*/
	Pawn(std::string position, char color, bool hasMoved, char type);

	/*
	Destructor for the Pawn class.
	input: none
	output: none
	*/
	~Pawn();

	/*
	Retrieves the moved status of the pawn.
	input: none
	output: bool - true if the pawn has moved, false otherwise
	*/
	bool getMovedStatus();

	/*
	Updates the moved status of the pawn.
	input: hasMoved (bool) - true if the pawn has moved, false otherwise
	output: none
	*/
	void setMovedStatus(bool hasMoved);

	/*
	Calculates all valid moves for the pawn based on the current state of the chessboard.
	input: chessBoard (const Board&) - the current state of the chessboard
	output: std::vector<std::string> - a list of valid moves for the pawn
	*/
	std::vector<std::string> move(const Board& chessBoard) override;
};
