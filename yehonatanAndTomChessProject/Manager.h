#pragma once
#include <string>
#include "Board.h"
#include "Player.h"

class Manager
{
private:
	char _currentTurn; // W for White and B for Black
	Board _board;
	Player _whitePlayer;
	Player _blackPlayer;

public:
	Manager(char firstTurn, Board board, Player whitePlayer, Player blackPlayer);
	~Manager();
	std::string convertBoardToString(Board board);
	static std::string convertMoveIntoCords(std::string position);
	char getCurrentTurn() const;
	void setCurrentTurn(char currentTurn);
	void printBoard(std::string boardString);
};