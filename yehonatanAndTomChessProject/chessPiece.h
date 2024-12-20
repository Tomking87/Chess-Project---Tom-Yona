#pragma once
#include <string>
class ChessPiece
{
protected:
	int _position;
	char _color;

	ChessPiece(int position, char color);
	virtual ~ChessPiece();
	virtual int move() = 0;
	virtual void checkForSelfChecks();
	virtual void checkForOpponentChecks();
};