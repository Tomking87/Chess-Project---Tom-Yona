#include "Board.h"
using namespace std;

#define rowLength 8
#define colLength 8

Board::Board()
{
	string zero = "0";
	this->_BoardGrid[0][0] = Square(false, nullptr, "00");//rook
	this->_BoardGrid[0][1] = Square(false, nullptr, "01");//knight
	this->_BoardGrid[0][2] = Square(false, nullptr, "02");//bishop
	this->_BoardGrid[0][3] = Square(false, nullptr, "03");//Queen
	this->_BoardGrid[0][4] = Square(false, nullptr, "04");//king
	this->_BoardGrid[0][5] = Square(false, nullptr, "05");//bishop
	this->_BoardGrid[0][6] = Square(false, nullptr, "06");//knight
	this->_BoardGrid[0][7] = Square(false, nullptr, "07");//rook
	// Setting up the second row with pawns
	for (int i = 0; i < rowLength; i++)
	{
		this->_BoardGrid[1][i] = Square(false, nullptr, zero + to_string(i));//Pawns
	}
	// Setting up rows 2 to 5 (empty squares
	for(int i=2; i<6;i++)
	{
		for(int j =0;j<rowLength;j++)
		{
			this->_BoardGrid[i][j] = Square(true, nullptr, to_string(i) + to_string(j));
		}
	}

	for (int i = 0; i < rowLength; i++)
	{
		this->_BoardGrid[1][i] = Square(false, nullptr, zero + to_string(i));//Pawns
	}

	this->_BoardGrid[7][0] = Square(false, nullptr, "70");//rook
	this->_BoardGrid[7][1] = Square(false, nullptr, "71");//knight
	this->_BoardGrid[7][2] = Square(false, nullptr, "72");//bishop
	this->_BoardGrid[7][3] = Square(false, nullptr, "73");//Queen
	this->_BoardGrid[7][4] = Square(false, nullptr, "74");//king
	this->_BoardGrid[7][5] = Square(false, nullptr, "75");//bishop
	this->_BoardGrid[7][6] = Square(false, nullptr, "76");//knight
	this->_BoardGrid[7][7] = Square(false, nullptr, "77");//rook


}
Board::~Board()
{

}
Square Board::getSquare() const // get a squere at the board
{

}
void Board::setBoard(Square square, std::string position) // sets a specific Square at the board
{

}
// take the algebretic notation and convert it into x and y cords in format: int xy
int Board::convertPositionToIntCords(std::string position)
{

}