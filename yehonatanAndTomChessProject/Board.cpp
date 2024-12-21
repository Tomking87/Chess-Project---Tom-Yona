#include "Board.h"
using namespace std;

#define rowLength 8
#define colLength 8

Board::Board()
{
	Rook whiteRookL("00", 'W');
	Rook whiteRookR("01", 'W');
	Knight whiteKnightL("02", 'W');
	Knight whiteKnightR("03", 'W');
	Bishop whiteBishopL("04", 'W');
	Bishop whiteBishopR("05", 'W');
	King whiteKing("06", 'W');
	King whiteQueen("07", 'W');

	Rook blackRookL("70", 'B');
	Knight blackKnightL("71", 'B');
	Bishop blackBishopL("72", 'B');
	King blackKing("73", 'B');
	Queen blackQueen("74", 'B');
	Bishop blackBishopR("75", 'B');
	Knight blackKnightR("76", 'B');
	Rook blackRookR("77", 'B');

	string zero = "0";

	this->_BoardGrid[0][0] = Square(false, &whiteRookL, "00");//rook
	this->_BoardGrid[0][1] = Square(false, &whiteKnightL, "01");//knight
	this->_BoardGrid[0][2] = Square(false, &whiteBishopL, "02");//bishop
	this->_BoardGrid[0][3] = Square(false, &whiteKing, "03");//Queen
	this->_BoardGrid[0][4] = Square(false, &whiteQueen, "04");//king
	this->_BoardGrid[0][5] = Square(false, &whiteBishopR, "05");//bishop
	this->_BoardGrid[0][6] = Square(false, &whiteKnightR, "06");//knight
	this->_BoardGrid[0][7] = Square(false, &whiteRookR, "07");//rook
	// Setting up the second row with pawns
	for (int i = 0; i < rowLength; i++)
	{
		this->_BoardGrid[1][i] = Square(false, &Pawn(zero + to_string(i), 'W', false), zero + to_string(i));//Pawns
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
		this->_BoardGrid[1][i] = Square(false, &Pawn(zero + to_string(i), 'B', false), zero + to_string(i));//Pawns
	}

	this->_BoardGrid[7][0] = Square(false, &blackRookL, "70");//rook
	this->_BoardGrid[7][1] = Square(false, &blackKnightL, "71");//knight
	this->_BoardGrid[7][2] = Square(false, &blackBishopL, "72");//bishop
	this->_BoardGrid[7][3] = Square(false, &blackKing, "73");//Queen
	this->_BoardGrid[7][4] = Square(false, &blackQueen, "74");//king
	this->_BoardGrid[7][5] = Square(false, &blackBishopR, "75");//bishop
	this->_BoardGrid[7][6] = Square(false, &blackKnightR, "76");//knight
	this->_BoardGrid[7][7] = Square(false, &blackRookR, "77");//rook


}
Board::~Board()
{
	this->_BoardGrid.clear();
}
Square Board::getSquare(int Xposition, int Yposition) const // get a squere at the board
{
	return this->_BoardGrid[Yposition][Xposition];
}
void Board::setSquareInBoard(Square mySquare, std::string position) // sets a specific Square at the board
{
	this->_BoardGrid[position[0]][position[1]] = mySquare;
}
// take the algebretic notation and convert it into x and y cords in format: int xy
std::string Board::convertPositionToIntCords(std::string position)
{
	std::string cords = "";
	char chara_h = position[0];
	char char1_7 = position[1];

	chara_h = chara_h - 'a' + '0';
	char1_7 = char1_7 - '1' + '0';
	// Combine the results into a string
    cords += char1_7; // Add the row
    cords += chara_h; // Add the column
}