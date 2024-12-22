#pragma once
#include <string>

class Player
{
private:
	char _color; // W for White and B for Black
	bool _isInCheck;

public:
	Player(char color, bool isInCheck);
	~Player();
	virtual void checkForSelfChecks();	// will check for all the checks in board
	virtual void checkForOpponentChecks(); 
	int checkMove(std::string move);
};