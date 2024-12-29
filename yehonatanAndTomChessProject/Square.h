#pragma once
#include <string>

class ChessPiece;
class Square
{
private:
	ChessPiece* _piece;
	bool _isEmpty;
	std::string _position;

public:
	/*
	Default constructor for the Square class. Initializes an empty square.
	input: none
	output: none
	*/
	Square();

	/*
	Constructor for the Square class.
	input: isEmpty (bool) - true if the square is empty, false otherwise,
		   piece (ChessPiece*) - pointer to the chess piece on the square,
		   position (string) - position of the square (e.g., "e4")
	output: none
	*/
	Square(bool isEmpty, ChessPiece* piece, std::string position);

	/*
	Destructor for the Square class.
	input: none
	output: none
	*/
	~Square();

	/*
	Retrieves the status of the square (empty or not).
	input: none
	output: bool - true if the square is empty, false otherwise
	*/
	bool getSquareStatus() const;

	/*
	Updates the empty status of the square.
	input: squareStatus (bool) - true if the square is now empty, false otherwise
	output: none
	*/
	void setSquareStatus(bool squareStatus);

	/*
	Retrieves the chess piece on the square.
	input: none
	output: ChessPiece* - pointer to the chess piece on the square
	*/
	ChessPiece* getChessPieceAtSquare() const;

	/*
	Retrieves the position of the square.
	input: none
	output: string - the position of the square (e.g., "e4")
	*/
	std::string getSquarePosition() const;

	/*
	Sets a chess piece on the square.
	input: piece (ChessPiece*) - pointer to the chess piece
	output: none
	*/
	void setPieceInSquare(ChessPiece* piece);
};
