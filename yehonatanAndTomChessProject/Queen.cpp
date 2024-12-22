#include "Queen.h"
#include "ChessPiece.h"
using namespace std;

Queen::Queen(std::string position, char color, char type) : ChessPiece(position, color, type)
{
	// already Implemented in chessPiece
}
Queen::~Queen()
{
	// already Implemented in chessPiece
}

string* Queen::move()
{
    string* myStr = new string[1];
    // Need to implement
    return myStr;
}