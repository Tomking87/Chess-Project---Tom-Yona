#include "Manager.h"
#include "ChessPiece.h"
#include <string>
#include <iostream>
using namespace std;

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
			if (board.getSquare(i, j).getSquareStatus() == true)
			{
				boardString.push_back('#');
			}
			else
			{
				ChessPiece* myChessPiece = board.getSquare(i, j).getChessPieceAtSquare();
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
	for(int i = 7; i >= 0; i--)
	{
		std::cout << i+1 << " |";
		for (int j = 0; j < 8; j++)
		{
			std::cout << " " << boardString[i*8 + j];
			count--;
		}
		std::cout << std::endl;
	}
	std::cout << "    - - - - - - - -" << std::endl;
	std::cout << "    a b c d e f g h" << std::endl;
}

// take the algebretic notation and convert it into x and y cords in format: int xy
std::string Manager::convertMoveIntoCords(std::string position)
{
	std::string cords = "";
	char chara_h = position[0];
	char char1_7 = position[1];

	chara_h = chara_h - 'a' + '0';
	char1_7 = char1_7 - '1' + '0';
	// Combine the results into a string
	cords += char1_7; // Add the row
	cords += chara_h; // Add the col

	return cords;
}

char Manager::getCurrentTurn() const
{
	return this->_currentTurn;
}
void Manager::setCurrentTurn(char currentTurn)
{
	this->_currentTurn = currentTurn;
}

int Manager::isMoveLeagal(string move, Board& chessBoard, string rawMove)
{
	cout << "entered function" << endl;
	string src_square = move.substr(0, 2);
	string dst_square = move.substr(2, 2);
	char src_row = move[0];
	char src_col = move[1];
	char dst_row = move[2];
	char dst_col = move[3];

	// check for Ileagal moves
	if (!isalpha(rawMove[0]) || !isdigit(rawMove[1]) || !isalpha(rawMove[2]) || !isdigit(rawMove[3]) || src_col < '0' || src_col > '7' || src_row < '0' || src_row > '7' || dst_col < '0' || dst_col > '7' || dst_row < '0' || dst_row > '7')
	{
		return 5; // indexes of squares are Ileagal
	}
	else if (src_square == dst_square)
	{
		return 7; // the src and dst square are the same
	}
	else if (chessBoard.getSquare(int(src_row) - 48, int(src_col) - 48).getChessPieceAtSquare() == nullptr || chessBoard.getSquare(int(src_row) - 48, int(src_col) - 48).getChessPieceAtSquare()->getChessPieceColor() != this->_currentTurn)
	{
		return 2; // the src square does not contain a chess piece of this player
	}
	else if (chessBoard.getSquare(int(dst_row) - 48, int(dst_col) - 48).getChessPieceAtSquare() != nullptr && chessBoard.getSquare(int(dst_row) - 48, int(dst_col) - 48).getChessPieceAtSquare()->getChessPieceColor() == this->_currentTurn)
	{
		if (chessBoard.getSquare(int(dst_row) - 48, int(dst_col) - 48).getChessPieceAtSquare()->getChessPieceColor() == this->_currentTurn)
		{
			return 3; // the dst square contains a chess piece of this player
		}
	}
	else // now check if the movement is correct for the piece
	{
		vector<string> possibleMoves = chessBoard.getSquare(int(src_row) - 48, int(src_col) - 48).getChessPieceAtSquare()->move(chessBoard);
		cout << chessBoard.getSquare(int(src_row) - 48, int(src_col) - 48).getChessPieceAtSquare()->getChessPieceColor() << endl;
		cout << chessBoard.getSquare(int(src_row) - 48, int(src_col) - 48).getChessPieceAtSquare()->getChessPieceType() << endl;
		
		for (int i = 0;i < possibleMoves.size();i++)
		{
			cout << "move: " << possibleMoves[i] << endl;
			if (move == possibleMoves[i]) // a possible move for the piece
			{
				if (this->_currentTurn == 'W')
				{
					bool isChecked = this->_whitePlayer.checkForSelfChecks(move, chessBoard); // will input the move and check if it causes any self checks
					if (isChecked == true)
					{
						return 4; // Invalid a check will occur on this player
					}
					else if (isChecked == false)
					{
						if (this->_whitePlayer.checkForOpponentChecks(move, chessBoard) == true) // caused a check to the opponent
						{
							return 1; // Valid a check will occur on opponent
						}
						else if (this->_whitePlayer.checkForOpponentChecks(move, chessBoard) == false)
						{
							return 0; // Valid move
						}
					}
				}
				else if (this->_currentTurn == 'B')
				{
					bool isChecked = this->_blackPlayer.checkForSelfChecks(move, chessBoard); // will input the move and check if it causes any self checks
					if (isChecked == true)
					{
						return 4; // Invalid a check will occur on this player
					}
					else if (isChecked == false)
					{
						if (this->_blackPlayer.checkForOpponentChecks(move, chessBoard) == true) // caused a check to the opponent
						{
							return 1; // Valid a check will occur on opponent
						}
						else if (this->_blackPlayer.checkForOpponentChecks(move, chessBoard) == false)
						{
							return 0; // Valid move
						}
					}
				}
			}
		}
		return 6; // an Ileagal move of the piece
	}
}