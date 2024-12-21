#pragma once
#include <string>
class ChessPiece
{
protected:
	int _Xposition;
	int _Yposition;
	char _color;
	char _type;
	

	ChessPiece(std::string position, char color, char type); // take the position and brake it down to the x and y positions
	virtual ~ChessPiece();
	virtual int move() = 0;

public:
	char getChessPieceColor();
	virtual void checkForSelfChecks();
	virtual void checkForOpponentChecks();
	char getChessPieceType();

};