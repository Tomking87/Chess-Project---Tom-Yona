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

std::vector<std::string> Rook::move(const Board& chessBoard)
{
	cout << "Entered rook move" << endl;
	Square currSquare = chessBoard.getSquare(0, 0);
	std::vector<std::string> validMoves; //store all valid moves
	int xPosition = this->_Xposition;
	int yPosition = this->_Yposition;
	bool isntEmpty = false;


	//to the right
	currSquare = chessBoard.getSquare(yPosition, xPosition+1);
	xPosition++;
	while(currSquare.getSquareStatus() == true && xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0) //while the square is empty
	{
		validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition)); //adds the current square to valid moves
		currSquare = chessBoard.getSquare(yPosition, xPosition); //set currSquare to the next position
		xPosition++;
	}
	ChessPiece& chessPieceAtdstSquare = *currSquare.getChessPieceAtSquare();
	if (currSquare.getSquareStatus() == false && chessPieceAtdstSquare.getChessPieceColor() == this->_color && xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0)
	{
		validMoves.pop_back();
	}
	
	xPosition = this->_Xposition;
	yPosition = this->_Yposition;

	//to the left
	currSquare = chessBoard.getSquare(yPosition, xPosition - 1);
	xPosition--;
	while (currSquare.getSquareStatus() == true && xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0) //while the square is empty
	{
		validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition)); //adds the current square to valid moves
		currSquare = chessBoard.getSquare(yPosition, xPosition); //set currSquare to the next position
		xPosition--;
	}
	ChessPiece& chessPieceAtdstSquare2 = *currSquare.getChessPieceAtSquare();
	if (currSquare.getSquareStatus() == false && chessPieceAtdstSquare2.getChessPieceColor() == this->_color && xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0)
	{
		validMoves.pop_back();
	}

	xPosition = this->_Xposition;
	yPosition = this->_Yposition;

	//up
	currSquare = chessBoard.getSquare(yPosition + 1, xPosition);
	yPosition++;
	while (currSquare.getSquareStatus() == true && xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0) //while the square is empty
	{
		validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition)); //adds the current square to valid moves
		currSquare = chessBoard.getSquare(yPosition, xPosition); //set currSquare to the next position
		yPosition++;
	}
	ChessPiece& chessPieceAtdstSquare3 = *currSquare.getChessPieceAtSquare();
	if (currSquare.getSquareStatus() == false && chessPieceAtdstSquare3.getChessPieceColor() == this->_color && xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0)
	{
		validMoves.pop_back();
	}

	xPosition = this->_Xposition;
	yPosition = this->_Yposition;

	//down
	currSquare = chessBoard.getSquare(yPosition - 1, xPosition);
	yPosition--;
	while (currSquare.getSquareStatus() == true && xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0) //while the square is empty
	{
		validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition)); //adds the current square to valid moves
		currSquare = chessBoard.getSquare(yPosition, xPosition); //set currSquare to the next position
		yPosition--;
	}
	ChessPiece& chessPieceAtdstSquare4 = *currSquare.getChessPieceAtSquare();
	if (currSquare.getSquareStatus() == false && chessPieceAtdstSquare4.getChessPieceColor() == this->_color && xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0)
	{
		validMoves.pop_back();
	}

	return validMoves;
}