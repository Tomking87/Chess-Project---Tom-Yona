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

std::vector<std::string> Knight::move(const Board& chessBoard)
{
    std::vector<std::string> validMoves;
    // Need to implement
    return validMoves;
}