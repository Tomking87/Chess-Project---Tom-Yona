#include "King.h"
#include "ChessPiece.h"
using namespace std;

King::King(std::string position, char color, char type) : ChessPiece(position, color, type)
{
    // already Implemented in chessPiece
}
King::~King()
{
    // already Implemented in chessPiece
}

string* King::move()
{
    string* myStr = new string[1];
    // Need to implement
    return myStr;
}