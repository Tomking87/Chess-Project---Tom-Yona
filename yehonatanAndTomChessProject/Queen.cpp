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

std::vector<std::string> Queen::move(Board chessBoard)
{
    std::vector<std::string> validMoves;
    // Need to implement
    return validMoves;
}