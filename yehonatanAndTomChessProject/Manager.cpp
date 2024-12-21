#include "Manager.h"
#include "ChessPiece.h"
#include <string>
#include <iostream>

Manager::Manager(char firstTurn, Board board, Player whitePlayer, Player blackPlayer) 
	: _currentTurn(firstTurn), _board(board), _whitePlayer(whitePlayer), _blackPlayer(blackPlayer) 
{

}

Manager::~Manager()
{
	// empty
}

std::string Manager::convertBoardToString(Board board)
{
	std::string boardString = "";
	for (int i = 0;i < 8;i++)
	{
		for (int j = 0;j < 8;j++)
		{
			ChessPiece* myChessPiece = board.getSquare(i, j).getChessPieceAtSquare();
			ChessPiece& myChessPieceObj = *myChessPiece;
			if (myChessPieceObj.getChessPieceColor() == 'W')
			{
				boardString.push_back() // continue to implement...
			}
			else if (myChessPieceObj.getChessPieceColor() == 'B')
			{

			}

			
		}
	}
}

void Manager::printBoard(std::string boardString)
{
	int count = 0;
	for(int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << " " << boardString[count];
			count++;
		}
		std::cout << std::endl;
	}
}