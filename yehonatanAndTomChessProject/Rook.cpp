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
    Square currSquare = chessBoard.getSquare(0, 0);
    std::vector<std::string> validMoves;
    int xPosition = this->_Xposition;
    int yPosition = this->_Yposition;

    //to the right
    xPosition = this->_Xposition + 1;
    while (xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0)
    {
        currSquare = chessBoard.getSquare(yPosition, xPosition);
        if (currSquare.getSquareStatus() == true) // empty square
        {
            validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            xPosition++;
        }
        else // square has a piece
        {
            ChessPiece& chessPieceAtdstSquare = *currSquare.getChessPieceAtSquare();
            if (chessPieceAtdstSquare.getChessPieceColor() != this->_color) // enemy piece
            {
                validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            }
            break;
        }
    }

    //to the left
    xPosition = this->_Xposition - 1;
    while (xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0)
    {
        currSquare = chessBoard.getSquare(yPosition, xPosition);
        if (currSquare.getSquareStatus() == true) // empty square
        {
            validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            xPosition--;
        }
        else // square has a piece
        {
            ChessPiece& chessPieceAtdstSquare = *currSquare.getChessPieceAtSquare();
            if (chessPieceAtdstSquare.getChessPieceColor() != this->_color) // enemy piece
            {
                validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            }
            break;
        }
    }

    //up
    xPosition = this->_Xposition;
    yPosition = this->_Yposition + 1;
    while (xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0)
    {
        currSquare = chessBoard.getSquare(yPosition, xPosition);
        if (currSquare.getSquareStatus() == true) // empty square
        {
            validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            yPosition++;
        }
        else // square has a piece
        {
            ChessPiece& chessPieceAtdstSquare = *currSquare.getChessPieceAtSquare();
            if (chessPieceAtdstSquare.getChessPieceColor() != this->_color) // enemy piece
            {
                validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            }
            break;
        }
    }

    //down
    xPosition = this->_Xposition;
    yPosition = this->_Yposition - 1;
    while (xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0)
    {
        currSquare = chessBoard.getSquare(yPosition, xPosition);
        if (currSquare.getSquareStatus() == true) // empty square
        {
            validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            yPosition--;
        }
        else // square has a piece
        {
            ChessPiece& chessPieceAtdstSquare = *currSquare.getChessPieceAtSquare();
            if (chessPieceAtdstSquare.getChessPieceColor() != this->_color) // enemy piece
            {
                validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            }
            break;
        }
    }
    return validMoves;
}