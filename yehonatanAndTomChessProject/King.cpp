#include "King.h"
#include "Board.h"
using namespace std;

King::King(std::string position, char color, char type) : ChessPiece(position, color, type)
{
    // already Implemented in chessPiece
}
King::~King()
{
    // already Implemented in chessPiece
}

std::vector<std::string> King::move(Board chessBoard)
{
    int XcordMove = 0;
    int YcordMove = 0;
    string destMovePosition = "";
    string completeMove = "";
	vector<string> validMoves; // vector to store all of the calculated valid moves

    //calc Top-left move
    int XcordMoveTL = this->_Xposition - 1;
    int YcordMoveTL = this->_Yposition + 1;
    //calc Top
    int XcordMoveT = this->_Xposition;
    int YcordMoveT = this->_Yposition + 1;
    //calc Top-right
    int XcordMoveTR = this->_Xposition + 1;
    int YcordMoveTR = this->_Yposition + 1;
    //calc right
    int XcordMoveR = this->_Xposition + 1;
    int YcordMoveR = this->_Yposition;
    //calc Bottom-right
    int XcordMoveBR = this->_Xposition + 1;
    int YcordMoveBR = this->_Yposition - 1;
    //calc Bottom
    int XcordMoveB = this->_Xposition;
    int YcordMoveB = this->_Yposition - 1;
    //calc Bottom-left
    int XcordMoveBL = this->_Xposition - 1;
    int YcordMoveBL = this->_Yposition - 1;
    //calc left
    int XcordMoveL = this->_Xposition - 1;
    int YcordMoveL = this->_Yposition;

    for (int i = 0;i < 8;i++)
    {
        if (i == 0)
        {
            XcordMove = XcordMoveTL;
            YcordMove = YcordMoveTL;
        }
        else if (i == 1)
        {
            XcordMove = XcordMoveT;
            YcordMove = YcordMoveT;
        }
        else if (i == 2)
        {
            XcordMove = XcordMoveTR;
            YcordMove = YcordMoveTR;
        }
        else if (i == 3)
        {
            XcordMove = XcordMoveR;
            YcordMove = YcordMoveR;
        }
        else if (i == 4)
        {
            XcordMove = XcordMoveBR;
            YcordMove = YcordMoveBR;
        }
        else if (i == 5)
        {
            XcordMove = XcordMoveB;
            YcordMove = YcordMoveB;
        }
        else if (i == 6)
        {
            XcordMove = XcordMoveBL;
            YcordMove = YcordMoveBL;
        }
        else if (i == 7)
        {
            XcordMove = XcordMoveL;
            YcordMove = YcordMoveL;
        }

        if (XcordMove < 0 || XcordMove > 7 || YcordMove < 0 || YcordMove > 7)
        {
            // nothing happens
        }
        else
        {
            if (chessBoard.getSquare(XcordMove, YcordMove).getSquareStatus() == true)
            {
                completeMove = to_string(this->_Yposition) + to_string(_Xposition) + to_string(YcordMove) + to_string(XcordMove);
                validMoves.push_back(completeMove);
            }
            else
            {
                ChessPiece* pointerChessPieceAtSquare = chessBoard.getSquare(XcordMove, YcordMove).getChessPieceAtSquare();
                if (pointerChessPieceAtSquare == nullptr)
                {
                    // square is empty
                }
                else if (pointerChessPieceAtSquare->getChessPieceColor() == this->_color)
                {
                    // nothing happens
                }
                else if (pointerChessPieceAtSquare->getChessPieceColor() != this->_color)
                {
                    completeMove = to_string(this->_Yposition) + to_string(_Xposition) + to_string(YcordMove) + to_string(XcordMove);
                    validMoves.push_back(completeMove);
                }
            }

        }
    }

    return validMoves;
}