#pragma once
#include "ChessPiece.h"
#include <string>

class Square
{
private:
	ChessPiece* _piece;
	bool _isEmpty;
	std::string _position;
public:
	Square(bool isEmpty, ChessPiece* piece, std::string position);
	~Square();
	bool getSquareStatus() const; // output is Empty
	void setSquareStatus(bool squareStatus); // input to isEmpty
};