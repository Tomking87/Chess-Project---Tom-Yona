#pragma once

class Player
{
private:
	char _color; // W for White and B for Black
	bool _isInCheck;

public:
	Player(char color, bool isInCheck);
	~Player();
	int Checks(); // will check for all the checks in board
};