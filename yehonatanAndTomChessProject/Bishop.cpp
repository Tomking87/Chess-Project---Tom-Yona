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
    std::vector<std::string> validMoves;
    // Need to implement
    return validMoves;
}