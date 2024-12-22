#include "Knight.h"
#include "ChessPiece.h"
using namespace std;

Knight::Knight(std::string position, char color, char type) : ChessPiece(position, color, type)
{
    // already Implemented in chessPiece
}
Knight::~Knight()
{
    // already Implemented in chessPiece
}

string* Knight::move()
{
    string* myStr = new string[1];
    // Need to implement
    return myStr;
}