#pragma once
#include "ChessPiece.h"

class Queen : public ChessPiece
{
public:
    /*
    Constructor for the Queen class. Initializes the queen with its position, color, and type.
    input: position (string) - initial position (e.g., "d1"),
           color (char) - 'W' for White or 'B' for Black,
           type (char) - 'Q' for Queen
    output: none
    */
    Queen(std::string position, char color, char type);

    /*
    Destructor for the Queen class.
    input: none
    output: none
    */
    ~Queen();

    /*
    Calculates all valid moves for the queen based on the current state of the chessboard.
    input: chessBoard (const Board&) - the current state of the chessboard
    output: std::vector<std::string> - a list of valid moves for the queen
    */
    std::vector<std::string> move(const Board& chessBoard) override;
};
