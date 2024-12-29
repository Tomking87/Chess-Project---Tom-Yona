#include "Queen.h"
#include "Board.h"
using namespace std;

Queen::Queen(std::string position, char color, char type) : ChessPiece(position, color, type)
{
	// already Implemented in chessPiece
}
Queen::~Queen()
{
	// already Implemented in chessPiece
}

std::vector<std::string> Queen::move(const Board& chessBoard)
{
    cout << "Entered queen move" << endl;
    Square currSquare = chessBoard.getSquare(0, 0);
    std::vector<std::string> validMoves;
    int xPosition = this->_Xposition;
    int yPosition = this->_Yposition;

    // Rook-like movements (horizontal and vertical)
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

    // Bishop-like movements (diagonals)
    xPosition = this->_Xposition;
    yPosition = this->_Yposition;

    // Up-right diagonal
    xPosition++; yPosition++;
    while (xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0)
    {
        currSquare = chessBoard.getSquare(yPosition, xPosition);
        if (currSquare.getSquareStatus() == true)
        {
            validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            xPosition++; yPosition++;
        }
        else
        {  // Square is occupied
            ChessPiece& chessPieceAtdstSquare = *currSquare.getChessPieceAtSquare();
            if (chessPieceAtdstSquare.getChessPieceColor() != this->_color)
            {
                validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            }
            break;
        }
    }

    xPosition = this->_Xposition;
    yPosition = this->_Yposition;

    // Up-left diagonal
    xPosition--; yPosition++;
    while (xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0)
    {
        currSquare = chessBoard.getSquare(yPosition, xPosition);
        if (currSquare.getSquareStatus() == true)
        {
            validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            xPosition--; yPosition++;
        }
        else
        {  // Square is occupied
            ChessPiece& chessPieceAtdstSquare = *currSquare.getChessPieceAtSquare();
            if (chessPieceAtdstSquare.getChessPieceColor() != this->_color)
            {
                validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            }
            break;
        }
    }

    xPosition = this->_Xposition;
    yPosition = this->_Yposition;

    // Down-right diagonal
    xPosition++; yPosition--;
    while (xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0)
    {
        currSquare = chessBoard.getSquare(yPosition, xPosition);
        if (currSquare.getSquareStatus() == true)
        {
            validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            xPosition++; yPosition--;
        }
        else
        {  // Square is occupied
            ChessPiece& chessPieceAtdstSquare = *currSquare.getChessPieceAtSquare();
            if (chessPieceAtdstSquare.getChessPieceColor() != this->_color)
            {
                validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            }
            break;
        }
    }

    xPosition = this->_Xposition;
    yPosition = this->_Yposition;

    // Down-left diagonal
    xPosition--; yPosition--;
    while (xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0)
    {
        currSquare = chessBoard.getSquare(yPosition, xPosition);
        if (currSquare.getSquareStatus() == true)
        {
            validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            xPosition--; yPosition--;
        }
        else
        {  // Square is occupied
            ChessPiece& chessPieceAtdstSquare = *currSquare.getChessPieceAtSquare();
            if (chessPieceAtdstSquare.getChessPieceColor() != this->_color)
            {
                validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            }
            break;
        }
    }

    return validMoves;
}