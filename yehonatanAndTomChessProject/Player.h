#pragma once
#include <string>
#include "Board.h"

class Player
{
private:
    char _color;
    bool _isInCheck;

public:
    /*
    Constructor for the Player class.
    input: color (char) - 'W' for White or 'B' for Black,
           isInCheck (bool) - true if the player is in check, false otherwise
    output: none
    */
    Player(char color, bool isInCheck);

    /*
    Destructor for the Player class.
    input: none
    output: none
    */
    ~Player();

    /*
    Checks for self-check scenarios after a move.
    input: move (string) - the move to evaluate,
           chessBoard (Board&) - the current state of the board
    output: bool - true if the player is still in check, false otherwise
    */
    virtual bool checkForSelfChecks(std::string move, Board& chessBoard);

    /*
    Checks if the opponent's king is in check after a move.
    input: move (string) - the move to evaluate,
           chessBoard (Board&) - the current state of the board
    output: bool - true if the opponent's king is in check, false otherwise
    */
    virtual bool checkForOpponentChecks(std::string move, Board& chessBoard);
};
