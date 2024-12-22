#include "Player.h"


Player::Player(char color, bool isInCheck)
{
	this->_color = color;
	this->_isInCheck = isInCheck;
}

Player::~Player()
{

}

void Player::checkForSelfChecks()
{
	//Need to implement
}

void Player::checkForOpponentChecks()
{
	//Need to implement
}