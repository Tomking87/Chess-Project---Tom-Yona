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
			if (board.getSquare(j, i).getSquareStatus() == true)
			{
				boardString.push_back('#');
			}
			else
			{
				ChessPiece* myChessPiece = board.getSquare(j, i).getChessPieceAtSquare();
				ChessPiece& myChessPieceObj = *myChessPiece;
				if (myChessPieceObj.getChessPieceColor() == 'W')
				{
					if (myChessPieceObj.getChessPieceType() == 'R')
					{
						boardString.push_back('R');
					}
					if (myChessPieceObj.getChessPieceType() == 'N')
					{
						boardString.push_back('N');
					}
					if (myChessPieceObj.getChessPieceType() == 'B')
					{
						boardString.push_back('B');
					}
					if (myChessPieceObj.getChessPieceType() == 'K')
					{
						boardString.push_back('K');
					}
					if (myChessPieceObj.getChessPieceType() == 'Q')
					{
						boardString.push_back('Q');
					}
					if (myChessPieceObj.getChessPieceType() == 'P')
					{
						boardString.push_back('P');
					}

				}
				else if (myChessPieceObj.getChessPieceColor() == 'B')
				{
					if (myChessPieceObj.getChessPieceType() == 'R')
					{
						boardString.push_back('r');
					}
					if (myChessPieceObj.getChessPieceType() == 'N')
					{
						boardString.push_back('n');
					}
					if (myChessPieceObj.getChessPieceType() == 'B')
					{
						boardString.push_back('b');
					}
					if (myChessPieceObj.getChessPieceType() == 'K')
					{
						boardString.push_back('k');
					}
					if (myChessPieceObj.getChessPieceType() == 'Q')
					{
						boardString.push_back('q');
					}
					if (myChessPieceObj.getChessPieceType() == 'P')
					{
						boardString.push_back('p');
					}
				}
			}
		}
	}

	return boardString;
}

void Manager::printBoard(std::string boardString)
{
	int count = 63;
	for(int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << " " << boardString[count];
			count--;
		}
		std::cout << std::endl;
	}
}