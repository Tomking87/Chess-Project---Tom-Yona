#pragma once
#include <string>
#include "Board.h"
#include "Player.h"

class Manager
{
private:
    char _currentTurn;
    Board _board;
    Player _whitePlayer;
    Player _blackPlayer;

public:
    /*
    Constructor for the Manager class. Initializes the game manager with starting parameters.
    input: firstTurn (char) - 'W' for White's turn first, 'B' for Black's,
           board (Board) - the chessboard instance,
           whitePlayer (Player) - the White player instance,
           blackPlayer (Player) - the Black player instance
    output: none
    */
    Manager(char firstTurn, Board board, Player whitePlayer, Player blackPlayer);

    /*
    Destructor for the Manager class.
    input: none
    output: none
    */
    ~Manager();

    /*
    Converts the current state of the chessboard into a string representation.
    input: board (Board) - the chessboard instance
    output: string - textual representation of the board
    */
    std::string convertBoardToString(Board board);

    /*
    Converts a move in standard notation into coordinate-based notation.
    input: position (string) - standard chess notation for the move (e.g., "e2e4")
    output: string - coordinate-based notation
    */
    static std::string convertMoveIntoCords(std::string position);

    /*
    Retrieves the current turn indicator.
    input: none
    output: char - 'W' for White or 'B' for Black
    */
    char getCurrentTurn() const;

    /*
    Updates the current turn.
    input: currentTurn (char) - 'W' for White or 'B' for Black
    output: none
    */
    void setCurrentTurn(char currentTurn);

    /*
    Prints the chessboard to the console in a readable format.
    input: boardString (string) - textual representation of the board
    output: none
    */
    void printBoard(std::string boardString);

    /*
    Validates if a move is legal based on the current state of the board.
    input: move (string) - the move to validate,
           chessBoard (Board&) - the current state of the board,
           rawMove (string) - the unprocessed move string
    output: int - a code indicating the legality of the move
    */
    int isMoveLeagal(std::string move, Board& chessBoard, std::string rawMove);

    /*
    Manages special pawn statuses such as promotion or en passant.
    input: moveCode (int) - code indicating the type of move,
           position (string) - current position of the pawn,
           chessBoard (const Board&) - the current state of the board
    output: none
    */
    void managePawnStatus(int moveCode, std::string position, const Board& chessBoard);
};
