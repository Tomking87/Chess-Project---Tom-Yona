#pragma once
//#include "ChessPiece.h"
#include <string>

class ChessPiece;

class Square
{
private:
	ChessPiece* _piece;
	bool _isEmpty;
	std::string _position;
public:
	Square();
	Square(bool isEmpty, ChessPiece* piece, std::string position);
	~Square();
	bool getSquareStatus() const; // output is Empty
	void setSquareStatus(bool squareStatus); // input to isEmpty
	ChessPiece* getChessPieceAtSquare() const;
	std::string getSquarePosition() const;
	void setPieceInSquare(ChessPiece* piece);
};