#pragma once
#include <string>
#include "Board.h"

class Player
{
private:
	char _color; // W for White and B for Black
	bool _isInCheck;

public:
	Player(char color, bool isInCheck);
	~Player();
	virtual bool checkForSelfChecks(std::string move, Board& chessBoard);	// will check for all the checks in board after the move and set isInCheck as so
	virtual bool checkForOpponentChecks(std::string move, Board& chessBoard);
};