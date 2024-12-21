#pragma once
#include <string>
class ChessPiece
{
protected:
	int Xposition;
	int Yposition;
	char _color;

	ChessPiece(std::string position, char color); // take the position and brake it down to the x and y positions
	virtual ~ChessPiece();
	virtual int move() = 0;
	virtual void checkForSelfChecks();
	virtual void checkForOpponentChecks();
};