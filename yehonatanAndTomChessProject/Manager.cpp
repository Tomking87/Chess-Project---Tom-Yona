#include "Manager.h"
#include "ChessPiece.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <random> // For std::random_device and std::mt19937
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
	string src_square = move.substr(0, 2);
	string dst_square = move.substr(2, 2);
	char src_row = move[0];
	char src_col = move[1];
	char dst_row = move[2];
	char dst_col = move[3];

	// check for Ileagal moves
	if (!isalpha(rawMove[0]) || !isdigit(rawMove[1]) || !isalpha(rawMove[2]) || !isdigit(rawMove[3]) || int(src_col) -48 < 0 || int(src_col) - 48 > 7 || int(src_row) - 48 < 0 || int(src_row) - 48> 7 || int(dst_col) - 48 < 0 || int(dst_col) -48 > 7 || int(dst_row) - 48< 0 || int(dst_row) - 48> 7 || rawMove.length() != 4)
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
		
		for (int i = 0;i < possibleMoves.size();i++)
		{
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
							if (this->_whitePlayer.checkForMate(move, chessBoard) == true) // check if the check was actully a mate
							{
								return 8; // Valid - CheckMate
							}
							else if (this->_whitePlayer.checkForMate(move, chessBoard) == false)
							{
								return 1; // Valid a check will occur on opponent
							}
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
							if (this->_blackPlayer.checkForMate(move, chessBoard) == true) // check if the check was actully a mate
							{
								return 8; // Valid - CheckMate
							}
							else if (this->_blackPlayer.checkForMate(move, chessBoard) == false)
							{
								return 1; // Valid a check will occur on opponent
							}
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

void Manager::managePawnStatus(int moveCode, string position, const Board& chessBoard)
{
	ChessPiece* myPiece = chessBoard.getSquare(int(position[0]) - 48, int(position[1]) - 48).getChessPieceAtSquare();
	if (myPiece != nullptr)
	{
		if (myPiece->getChessPieceType() == 'P')
		{
			Pawn* myPawn = dynamic_cast<Pawn*>(myPiece); // use dynamic casting to cast the chess piece into a pawn object
			if ((moveCode == 0 || moveCode == 1 || moveCode == 8) && myPawn->getMovedStatus() == false)
			{
				myPawn->setMovedStatus(true);
			}
		}
	}
}

void Manager::printASCII(int artChoice)
{
	std::string openingMsg = R"(
  /$$$$$$  /$$                                        ,....,
 /$$__  $$| $$                                       ,::::::<
| $$  \__/| $$$$$$$   /$$$$$$   /$$$$$$$  /$$$$$$$    ,::/^\"`.
| $$      | $$__  $$ /$$__  $$ /$$_____/ /$$_____/    ,::/,    e.
| $$      | $$  \ $$| $$$$$$$$|  $$$$$$ |  $$$$$$     ,::; |        '.
| $$    $$| $$  | $$| $$_____/ \____  $$ \____  $$    ,::|  \___,-.  c)
|  $$$$$$/| $$  | $$|  $$$$$$$ /$$$$$$$/ /$$$$$$$/    ;::|     \   '-'
 \______/ |__/  |__/ \_______/|_______/ |_______/     ;::|      \
                                                      ;::|   _.=\
                                                      ;:|.= _.=\
   By Tom and Yehonatan.                              '|_.=   __\
                                                        \_..== /
                                                       .'.___.-'.
                                                      /          \
                                                     ('--......--')
                                                     /'--......--'\
                                                      "--......--"
    )";

	string CheckMateMsg = R"(
  /$$$$$$  /$$                           /$$       /$$      /$$             /$$                  
 /$$__  $$| $$                          | $$      | $$$    /$$$            | $$                  
| $$  \__/| $$$$$$$   /$$$$$$   /$$$$$$$| $$   /$$| $$$$  /$$$$  /$$$$$$  /$$$$$$    /$$$$$$     
| $$      | $$__  $$ /$$__  $$ /$$_____/| $$  /$$/| $$ $$/$$ $$ |____  $$|_  $$_/   /$$__  $$    
| $$      | $$  \ $$| $$$$$$$$| $$      | $$$$$$/ | $$  $$$| $$  /$$$$$$$  | $$    | $$$$$$$$    
| $$    $$| $$  | $$| $$_____/| $$      | $$_  $$ | $$\  $ | $$ /$$__  $$  | $$ /$$| $$_____/    
|  $$$$$$/| $$  | $$|  $$$$$$$|  $$$$$$$| $$ \  $$| $$ \/  | $$|  $$$$$$$  |  $$$$/|  $$$$$$$ /$$
 \______/ |__/  |__/ \_______/ \_______/|__/  \__/|__/     |__/ \_______/   \___/   \_______/|__/)";

	
	if (artChoice == 0)
	{
		cout << openingMsg << endl;
	}
	else if (artChoice == 1)
	{
		cout << CheckMateMsg << endl << endl;
	}
}

void Manager::promotion(Board& chessBoard)
{
	char chessPiece = ' ';
	Square currSquare = chessBoard.getSquare(0, 0);
	for (int i = 0; i < 8; i++)
	{
		currSquare = chessBoard.getSquare(7, i);
		if (currSquare.getChessPieceAtSquare() != nullptr)
		{
			if (currSquare.getChessPieceAtSquare()->getChessPieceType() == 'P')
			{
				std::string position = currSquare.getChessPieceAtSquare()->getCords();
				std::cout << "promotion!" << std::endl;
				std::cout << "select the chessPiece you would like:" << std::endl;
				std::cout << "R - Rook" << std::endl;
				std::cout << "N - Knight" << std::endl;
				std::cout << "Q - Queen" << std::endl;
				std::cout << "B - Bishop" << std::endl;
				std::cout << "position: " << position << std::endl;
				std::cin >> chessPiece;
				if (chessPiece == 'R')
				{
					currSquare = Square(false, new Rook(position, 'W', 'R'), position);
					chessBoard.setSquareInBoard(currSquare, position);
				}
				if (chessPiece == 'N')
				{
					currSquare = Square(false, new Knight(position, 'W', 'N'), position);
					chessBoard.setSquareInBoard(currSquare, position);
				}
				if (chessPiece == 'Q')
				{
					currSquare = Square(false, new Queen(position, 'W', 'Q'), position);
					chessBoard.setSquareInBoard(currSquare, position);
				}
				if (chessPiece == 'B')
				{
					currSquare = Square(false, new Bishop(position, 'W', 'B'), position);
					chessBoard.setSquareInBoard(currSquare, position);
				}
			}
		}
	}


	for (int i = 0; i < 8; i++)
	{
		currSquare = chessBoard.getSquare(0, i);
		if (currSquare.getChessPieceAtSquare() != nullptr)
		{
			if (currSquare.getChessPieceAtSquare()->getChessPieceType() == 'P')
			{
				std::string position = currSquare.getChessPieceAtSquare()->getCords();
				std::cout << "promotion!" << std::endl;
				std::cout << "select the chessPiece you would like:" << std::endl;
				std::cout << "r - Rook" << std::endl;
				std::cout << "n - Knight" << std::endl;
				std::cout << "q - Queen" << std::endl;
				std::cout << "b - Bishop" << std::endl;
				std::cout << "position: " << position << std::endl;
				std::cin >> chessPiece;
				if (chessPiece == 'r')
				{
					currSquare = Square(false, new Rook(position, 'B', 'R'), position);
					chessBoard.setSquareInBoard(currSquare, position);
				}
				if (chessPiece == 'n')
				{
					currSquare = Square(false, new Knight(position, 'B', 'N'), position);
					chessBoard.setSquareInBoard(currSquare, position);
				}
				if (chessPiece == 'q')
				{
					currSquare = Square(false, new Queen(position, 'B', 'Q'), position);
					chessBoard.setSquareInBoard(currSquare, position);
				}
				if (chessPiece == 'b')
				{
					currSquare = Square(false, new Bishop(position, 'B', 'B'), position);
					chessBoard.setSquareInBoard(currSquare, position);
				}
			}
		}
	}
}

std::vector<char> Manager::shuffle()
{
	int counter = 0;
	bool foundFirstBishop = false;

	// create an array for the back rank
	std::vector<char> backRank = { 'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R' };

	while (true)
	{
		counter = 0;
		foundFirstBishop = false;

		// Create a random number generator
		std::random_device rd; // Seed
		std::mt19937 g(rd());  // Mersenne Twister random number generator

		// Shuffle the array
		std::shuffle(backRank.begin(), backRank.end(), g);

		// check for the Bishops placments
		for (int i = 0;i < backRank.size();i++)
		{
			if (backRank[i] == 'B' && foundFirstBishop == false) // Found the first bishop
			{
				counter++;
				foundFirstBishop = true;
			}
			else if (backRank[i] == 'B' && foundFirstBishop == true)
			{
				counter++;
				if (counter % 2 == 0)
				{
					return backRank;
				}
				else
				{
					break; // reshuffle
				}
			}
			else if (foundFirstBishop == true)
			{
				counter++;
			}
		}
	}
}