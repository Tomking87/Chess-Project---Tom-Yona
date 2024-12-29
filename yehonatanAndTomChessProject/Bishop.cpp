#include "Bishop.h"
#include "Board.h"
using namespace std;

Bishop::Bishop(std::string position, char color, char type) : ChessPiece(position, color, type)
{
    // already Implemented in chessPiece
}

Bishop::~Bishop()
{
    // already Implemented in chessPiece
}

std::vector<std::string> Bishop::move(const Board& chessBoard)
{
    cout << "Entered bishop move" << endl;
    Square currSquare = chessBoard.getSquare(0, 0);
    std::vector<std::string> validMoves;
    int xPosition = this->_Xposition;
    int yPosition = this->_Yposition;

    // Up-right diagonal
    xPosition++; yPosition++;
    while (xPosition <= 7 && xPosition >= 0 && yPosition <= 7 && yPosition >= 0)
    {
        currSquare = chessBoard.getSquare(yPosition, xPosition);
        if (currSquare.getSquareStatus() == true)
        {
            validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            currSquare = chessBoard.getSquare(yPosition, xPosition);
            xPosition++; yPosition++;
        }
        else
        {  // Square is occupied
            ChessPiece& chessPieceAtdstSquare = *currSquare.getChessPieceAtSquare();
            if (chessPieceAtdstSquare.getChessPieceColor() != this->_color)
            {
                validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            }
            break;  // Stop after handling the occupied square
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
            currSquare = chessBoard.getSquare(yPosition, xPosition);
            xPosition--; yPosition++;
        }
        else
        {  // Square is occupied
            ChessPiece& chessPieceAtdstSquare = *currSquare.getChessPieceAtSquare();
            if (chessPieceAtdstSquare.getChessPieceColor() != this->_color)
            {
                validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            }
            break;  // Stop after handling the occupied square
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
            currSquare = chessBoard.getSquare(yPosition, xPosition);
            xPosition++; yPosition--;
        }
        else
        {  // Square is occupied
            ChessPiece& chessPieceAtdstSquare = *currSquare.getChessPieceAtSquare();
            if (chessPieceAtdstSquare.getChessPieceColor() != this->_color)
            {
                validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            }
            break;  // Stop after handling the occupied square
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
            currSquare = chessBoard.getSquare(yPosition, xPosition);
            xPosition--; yPosition--;
        }
        else
        {  // Square is occupied
            ChessPiece& chessPieceAtdstSquare = *currSquare.getChessPieceAtSquare();
            if (chessPieceAtdstSquare.getChessPieceColor() != this->_color)
            {
                validMoves.push_back(to_string(this->_Yposition) + to_string(this->_Xposition) + to_string(yPosition) + to_string(xPosition));
            }
            break;  // Stop after handling the occupied square
        }
    }
    return validMoves;
}