#include "Knight.h"
#include "Board.h"

using namespace std;

Knight::Knight(std::string position, char color, char type) : ChessPiece(position, color, type)
{
    // already Implemented in chessPiece
}
Knight::~Knight()
{
    // already Implemented in chessPiece
}

std::vector<std::string> Knight::move(const Board& board)
{
    std::vector<std::string> validMoves;
    int xPosition = this->_Xposition;
    int yPosition = this->_Yposition;
    int moves[8][2] = { {2, 1},{2, -1},{-2, 1},{-2, -1},{1, 2},{1, -2},{-1, 2},{-1, -2} };

    for (int i = 0; i < 8; i++)
    {
        int newY = yPosition + moves[i][0];
        int newX = xPosition + moves[i][1];

        if (newX >= 0 && newX <= 7 && newY >= 0 && newY <= 7)
        {
            Square currSquare = board.getSquare(newY, newX);

            if (currSquare.getSquareStatus() == true) // Empty square
            {
                validMoves.push_back(to_string(yPosition) + to_string(xPosition) + to_string(newY) + to_string(newX));
            }
            else // not empty square
            {
                ChessPiece& chessPieceAtdstSquare = *currSquare.getChessPieceAtSquare();
                if (chessPieceAtdstSquare.getChessPieceColor() != this->_color) //if not the same color
                {
                    validMoves.push_back(to_string(yPosition) + to_string(xPosition) + to_string(newY) + to_string(newX));
                }
            }
        }
    }

    return validMoves;
}