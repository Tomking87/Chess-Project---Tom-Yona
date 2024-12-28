#include "Player.h"
using namespace std;


Player::Player(char color, bool isInCheck)
{
	this->_color = color;
	this->_isInCheck = isInCheck;
}

Player::~Player()
{

}

bool Player::checkForSelfChecks(std::string move, Board& chessBoard) 
{
	//Need to implement
	return false;
}

bool Player::checkForOpponentChecks(std::string move, Board& chessBoard)
{
	//Need to implement
	return false;
}