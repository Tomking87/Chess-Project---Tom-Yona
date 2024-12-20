#pragma once
#include "ChessPiece.h"

class Square
{
private:
	ChessPiece* _piece;
	bool _isEmpty;
	int _position;
public:
	Square(bool isEmpty, ChessPiece* piece, int position);
	~Square();
	bool getSquareStatus() const; // output is Empty
	void setSquareStatus(bool squareStatus); // input to isEmpty
};