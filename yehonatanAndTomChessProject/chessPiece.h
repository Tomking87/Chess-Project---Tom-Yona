#pragma once
#include <string>
#include <vector>

class Board;

class ChessPiece
{
protected:
	int _Xposition;
	int _Yposition;
	char _color;
	char _type;
	

	ChessPiece(std::string position, char color, char type); // take the position and brake it down to the x and y positions
	virtual ~ChessPiece();
	virtual std::vector<std::string> move(Board chessBoard) = 0;

public:
	char getChessPieceColor();
	char getChessPieceType();

};