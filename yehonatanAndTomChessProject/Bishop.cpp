#include "Bishop.h"
#include "ChessPiece.h"
using namespace std;

Bishop::Bishop(std::string position, char color, char type) : ChessPiece(position, color, type)
{
    // already Implemented in chessPiece
}

Bishop::~Bishop()
{
    // already Implemented in chessPiece
}

 string* Bishop::move()
{
     string* myStr = new string[1];
    // Need to implement
    return myStr;
}