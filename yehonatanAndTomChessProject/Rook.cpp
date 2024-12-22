#include "Rook.h"
#include "ChessPiece.h"
using namespace std;

Rook::Rook(std::string position, char color, char type) : ChessPiece(position, color, type)
{
	// already Implemented in chessPiece
}
Rook::~Rook()
{
	// already Implemented in chessPiece
}

string* Rook::move()
{
    string* myStr = new string[1];
    // Need to implement
    return myStr;
}