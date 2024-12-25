#include "Rook.h"
#include "Board.h"

using namespace std;

Rook::Rook(std::string position, char color, char type) : ChessPiece(position, color, type)
{
	// already Implemented in chessPiece
}
Rook::~Rook()
{
	// already Implemented in chessPiece
}

std::vector<std::string> Rook::move(Board chessBoard)
{
	Square currSquare = chessBoard.getSquare(0, 0);
	std::vector<std::string> validMoves; //store all valid moves
	int i = 0;
	int j = 0;
	int xPosition = this->_Xposition;
	int yPosition = this->_Yposition;
	bool isntEmpty = false;


	//to the right
	currSquare = chessBoard.getSquare(this->_Xposition + 1, this->_Yposition);
	while(currSquare.getSquareStatus() == true && xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0) //while the square is empty
	{
		validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition)); //adds the current square to valid moves
		xPosition++;
		currSquare = chessBoard.getSquare(xPosition, yPosition); //set currSquare to the next position
	}
	ChessPiece& chessPieceAtdstSquare = *currSquare.getChessPieceAtSquare();
	if (currSquare.getSquareStatus() == false && chessPieceAtdstSquare.getChessPieceColor() != this->_color && xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0)
	{
		validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition)); //adds the current square to valid moves
	}

	//to the left
	currSquare = chessBoard.getSquare(this->_Xposition - 1, this->_Yposition);
	while (currSquare.getSquareStatus() == true && xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0) //while the square is empty
	{
		validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition)); //adds the current square to valid moves
		xPosition--;
		currSquare = chessBoard.getSquare(xPosition, yPosition); //set currSquare to the next position
	}
	chessPieceAtdstSquare = *currSquare.getChessPieceAtSquare();
	if (currSquare.getSquareStatus() == false && chessPieceAtdstSquare.getChessPieceColor() != this->_color && xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0)
	{
		validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition)); //adds the current square to valid moves
	}

	//up
	currSquare = chessBoard.getSquare(this->_Xposition, this->_Yposition + 1);
	while (currSquare.getSquareStatus() == true && xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0) //while the square is empty
	{
		validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition)); //adds the current square to valid moves
		yPosition++;
		currSquare = chessBoard.getSquare(xPosition, yPosition); //set currSquare to the next position
	}
	chessPieceAtdstSquare = *currSquare.getChessPieceAtSquare();
	if (currSquare.getSquareStatus() == false && chessPieceAtdstSquare.getChessPieceColor() != this->_color && xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0)
	{
		validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition)); //adds the current square to valid moves
	}

	//down
	currSquare = chessBoard.getSquare(this->_Xposition, this->_Yposition - 1);
	while (currSquare.getSquareStatus() == true && xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0) //while the square is empty
	{
		validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition)); //adds the current square to valid moves
		yPosition--;
		currSquare = chessBoard.getSquare(xPosition, yPosition); //set currSquare to the next position
	}
	chessPieceAtdstSquare = *currSquare.getChessPieceAtSquare();
	if (currSquare.getSquareStatus() == false && chessPieceAtdstSquare.getChessPieceColor() != this->_color && xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0)
	{
		validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition)); //adds the current square to valid moves
	}

	return validMoves;
}