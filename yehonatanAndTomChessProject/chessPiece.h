#pragma once
#include <string>
#include <vector>

class Board;
class ChessPiece {
protected:
	int _Xposition;
	int _Yposition;
	char _color;
	char _type;

	/*
	Constructor for the ChessPiece class. Initializes the position, color, and type of the chess piece.
	input: position (string) - chessboard position (e.g., "e2"),
		   color (char) - 'W' for White or 'B' for Black,
		   type (char) - piece type ('P' for Pawn, 'K' for King, etc.)
	output: none
	*/
	ChessPiece(std::string position, char color, char type);

	/*
	Destructor for the ChessPiece class. Cleans up resources used by the object.
	input: none
	output: none
	*/
	virtual ~ChessPiece();

public:
	/*
	Retrieves the color of the chess piece.
	input: none
	output: char - 'W' for White or 'B' for Black
	*/
	char getChessPieceColor();

	/*
	Retrieves the type of the chess piece.
	input: none
	output: char - the type of the chess piece ('P', 'K', etc.)
	*/
	char getChessPieceType();

	/*
	Pure virtual function to calculate all valid moves for the chess piece.
	input: chessBoard (const Board&) - the current state of the chessboard
	output: std::vector - a list of valid moves for the piece
	*/
	virtual std::vector<std::string> move(const Board& chessBoard) = 0;

	/*
	Retrieves the current coordinates of the chess piece as a string.
	input: none
	output: string - the position in chess notation (e.g., "e2")
	*/
	std::string getCords();

	/*
	Updates the coordinates of the chess piece.
	input: Ypos (int) - new row position,
		   Xpos (int) - new column position
	output: none
	*/
	void setCords(int Ypos, int Xpos);
};
