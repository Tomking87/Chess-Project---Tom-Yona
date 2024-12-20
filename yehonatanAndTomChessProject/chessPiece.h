#pragma once
#include <string>
class chessPeice
{
protected:
	std::string position;
	int color;

	virtual int move() = 0;
	virtual void checkForSelfChecks();
	virtual void checkForOpponentChecks();
};