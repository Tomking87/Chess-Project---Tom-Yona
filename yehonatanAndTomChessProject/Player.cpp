#include "Player.h"
using namespace std;
#define numOfRows 8
#define numOfCols 8


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
	vector<string> AllEnemyValidMoves;
	string src_square = move.substr(0, 2);
	string dst_square = move.substr(2, 2);
	char src_row = move[0];
	char src_col = move[1];
	char dst_row = move[2];
	char dst_col = move[3];
	Square mySquare;
	bool isSquareEmpty = true;
	string kingCords = "";
	bool retValue = false;

	if (chessBoard.getSquare(int(dst_row) - 48, int(dst_col) - 48).getChessPieceAtSquare() != nullptr) // dst square is not empty
	{
		mySquare = chessBoard.getSquare(int(dst_row) - 48, int(dst_col) - 48); // save the square
		isSquareEmpty = false;
	}
	chessBoard.updateBoard(move);

	// check check stuff

	// get all enemy valid moves
	for (int i = 0; i < numOfRows; i++)
	{
		for (int j = 0; j < numOfCols; j++)
		{
			const Square& square = chessBoard.getSquare(i, j);

			if (square.getSquareStatus() == false) // Check if the square is empty
			{
				ChessPiece* piece = square.getChessPieceAtSquare();

				if (piece != nullptr && piece->getChessPieceColor() != this->_color)
				{
					std::vector<std::string> validMoves = piece->move(chessBoard);
					AllEnemyValidMoves.insert(AllEnemyValidMoves.end(), validMoves.begin(), validMoves.end()); // add the valid moves to AllValidMoves
				}
			}
		}
	}
	
	// get the this king's cords
	for (int i = 0;i < numOfRows;i++)
	{
		for (int j = 0;j < numOfCols;j++)
		{
			if (chessBoard.getSquare(i, j).getSquareStatus() == false)
			{
				if (chessBoard.getSquare(i, j).getChessPieceAtSquare()->getChessPieceColor() == this->_color && chessBoard.getSquare(i, j).getChessPieceAtSquare()->getChessPieceType() == 'K')
				{
					kingCords = chessBoard.getSquare(i, j).getChessPieceAtSquare()->getCords();
				}
			}
		}
	}
	
	// check if enemy king's cords are in the validMoves list
	for (int i = 0;i < AllEnemyValidMoves.size();i++)
	{
		if (AllEnemyValidMoves[i].substr(2, 2) == kingCords)
		{
			retValue = true; // there is a check set retValue to true
		}
	}
	
	// return board to original
	chessBoard.updateBoard(dst_square + src_square);
	if (isSquareEmpty == false)
	{
		chessBoard.setSquareInBoard(mySquare, dst_square);
	}
	return retValue;
}

bool Player::checkForOpponentChecks(std::string move, Board& chessBoard)
{
	vector<string> AllValidMoves;
	string src_square = move.substr(0, 2);
	string dst_square = move.substr(2, 2);
	char src_row = move[0];
	char src_col = move[1];
	char dst_row = move[2];
	char dst_col = move[3];
	Square mySquare;
	bool isSquareEmpty = true;
	string enemyKingCords = "";
	bool retValue = false;

	if (chessBoard.getSquare(int(dst_row) - 48, int(dst_col) - 48).getChessPieceAtSquare() != nullptr) // dst square is not empty
	{
		mySquare = chessBoard.getSquare(int(dst_row) - 48, int(dst_col) - 48); // save the square
		isSquareEmpty = false;
	}
	chessBoard.updateBoard(move);

	// check check stuff

	// get all valid moves
	for (int i = 0; i < numOfRows; i++) 
	{
		for (int j = 0; j < numOfCols; j++) 
		{
			const Square& square = chessBoard.getSquare(i, j);

			if (square.getSquareStatus() == false) // Check if the square is empty
			{ 
				ChessPiece* piece = square.getChessPieceAtSquare();

				if (piece != nullptr && piece->getChessPieceColor() == this->_color) 
				{
					std::vector<std::string> validMoves = piece->move(chessBoard);
					AllValidMoves.insert(AllValidMoves.end(), validMoves.begin(), validMoves.end()); // add the valid moves to AllValidMoves
				}
			}
		}
	}

	// get the enemy king's cords
	for (int i = 0;i < numOfRows;i++)
	{
		for (int j = 0;j < numOfCols;j++)
		{
			if (chessBoard.getSquare(i, j).getSquareStatus() == false)
			{
				if (chessBoard.getSquare(i, j).getChessPieceAtSquare()->getChessPieceColor() != this->_color && chessBoard.getSquare(i, j).getChessPieceAtSquare()->getChessPieceType() == 'K')
				{
					enemyKingCords = chessBoard.getSquare(i, j).getChessPieceAtSquare()->getCords();
				}
			}
		}
	}

	// check if enemy king's cords are in the validMoves list
	for (int i = 0;i < AllValidMoves.size();i++)
	{
		if (AllValidMoves[i].substr(2, 2) == enemyKingCords)
		{
			retValue = true; // there is a check set retValue to true
		}
	}

	// return board to original
	chessBoard.updateBoard(dst_square + src_square);
	if (isSquareEmpty == false)
	{
		chessBoard.setSquareInBoard(mySquare, dst_square);
	}

	return retValue;
}