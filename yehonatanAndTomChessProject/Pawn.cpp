#include "Pawn.h"
#include "Board.h"

using namespace std;


Pawn::Pawn(std::string position, char color, bool hasMoved, char type) : ChessPiece(position, color, type)
{
	this->_hasMoved = hasMoved;
}

Pawn::~Pawn()
{
	// already Implemented in chessPiece
}

std::vector<std::string> Pawn::move(const Board& chessBoard)
{
    std::vector<std::string> validMoves;
    int xPosition = this->_Xposition;
    int yPosition = this->_Yposition;

    // Set direction based on color
    int direction;
    if (this->_color == 'W')
        direction = 1;
    else
        direction = -1;

    Square currSquare = chessBoard.getSquare(0, 0);

    // Forward move
    int newY = yPosition + direction;
    if (newY <= 7 && newY >= 0)  // Check board boundaries
    {
        currSquare = chessBoard.getSquare(newY, xPosition);
        if (currSquare.getSquareStatus() == true)  // Empty square ahead
        {
            validMoves.push_back(to_string(yPosition) + to_string(xPosition) + to_string(newY) + to_string(xPosition));

            // Two squares forward on first move
            if (!this->_hasMoved)
            {
                int twoSquaresY = yPosition + (2 * direction);
                if (twoSquaresY <= 7 && twoSquaresY >= 0)  // Check board boundaries
                {
                    currSquare = chessBoard.getSquare(twoSquaresY, xPosition);
                    if (currSquare.getSquareStatus() == true)  // Empty square two ahead
                    {
                        validMoves.push_back(to_string(yPosition) + to_string(xPosition) +
                            to_string(twoSquaresY) + to_string(xPosition));
                    }
                }
            }
        }
    }

    // Diagonal captures
    for (int xOffset = -1; xOffset <= 1; xOffset += 2)  // Check both left and right diagonals
    {
        int newX = xPosition + xOffset;
        newY = yPosition + direction;

        if (newX <= 7 && newX >= 0 && newY <= 7 && newY >= 0)  // Check board boundaries
        {
            currSquare = chessBoard.getSquare(newY, newX);
            if (currSquare.getSquareStatus() == false)  // Square has a piece
            {
                ChessPiece& chessPieceAtdstSquare = *currSquare.getChessPieceAtSquare();
                if (chessPieceAtdstSquare.getChessPieceColor() != this->_color)  // Enemy piece
                {
                    validMoves.push_back(to_string(yPosition) + to_string(xPosition) + to_string(newY) + to_string(newX));
                }
            }
        }
    }

    return validMoves;
}

bool Pawn::getMovedStatus()
{
    return this->_hasMoved;
}

void Pawn::setMovedStatus(bool hasMoved)
{
    this->_hasMoved = hasMoved;
}