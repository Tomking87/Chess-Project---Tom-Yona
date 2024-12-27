#include "Board.h"
using namespace std;

#define rowLength 8
#define colLength 8

Board::Board()
{
	_BoardGrid.resize(8, vector<Square>(8));

	for (int row = 0; row < 8; ++row) {
		for (int col = 0; col < 8; ++col) {
			_BoardGrid[row][col] = Square(true, nullptr, to_string(row) + to_string(col));
		}
	}

	string zero = "0";

	//this->_BoardGrid[0][0] = Square(false, new Rook("00", 'W', 'R'), "00"); // rook
	this->_BoardGrid[0][1] = Square(false, new Knight("01", 'W', 'N'), "01"); // knight
	this->_BoardGrid[0][2] = Square(false, new Bishop("02", 'W', 'B'), "02"); // bishop
	//this->_BoardGrid[0][3] = Square(false, new King("03", 'W', 'K'), "03"); // king
	this->_BoardGrid[0][4] = Square(false, new Queen("04", 'W', 'Q'), "04"); // queen
	this->_BoardGrid[0][5] = Square(false, new Bishop("05", 'W', 'B'), "05"); // bishop
	this->_BoardGrid[0][6] = Square(false, new Knight("06", 'W', 'N'), "06"); // knight
	this->_BoardGrid[0][7] = Square(false, new Rook("07", 'W', 'R'), "07"); // rook
	

	// Setting up the second row with white pawns
	this->_BoardGrid[1][0] = Square(false, new Pawn("10", 'W', false, 'P'), "10");//pawn
	this->_BoardGrid[1][1] = Square(false, new Pawn("11", 'W', false, 'P'), "11");//pawn
	this->_BoardGrid[1][2] = Square(false, new Pawn("12", 'W', false, 'P'), "12");//pawn
	this->_BoardGrid[1][3] = Square(false, new Pawn("13", 'W', false, 'P'), "13");//pawn
	this->_BoardGrid[1][4] = Square(false, new Pawn("14", 'W', false, 'P'), "14");//pawn
	this->_BoardGrid[1][5] = Square(false, new Pawn("15", 'W', false, 'P'), "15");//pawn
	this->_BoardGrid[1][6] = Square(false, new Pawn("16", 'W', false, 'P'), "16");//pawn
	this->_BoardGrid[1][7] = Square(false, new Pawn("17", 'W', false, 'P'), "17");//pawn


	// Setting up rows 2 to 5 (empty squares
	for (int i = 2; i < 6;i++)
	{
		for (int j = 0;j < rowLength;j++)
		{
			this->_BoardGrid[i][j] = Square(true, nullptr, to_string(i) + to_string(j));
		}
	}

	this->_BoardGrid[3][5] = Square(false, new King("35", 'W', 'K'), "35"); // king
	this->_BoardGrid[3][6] = Square(false, new Rook("36", 'W', 'R'), "36"); // rook

	// setting up black pawns
	this->_BoardGrid[6][0] = Square(false, new Pawn("60", 'B', false, 'P'), "60");//pawn
	this->_BoardGrid[6][1] = Square(false, new Pawn("61", 'B', false, 'P'), "61");//pawn
	this->_BoardGrid[6][2] = Square(false, new Pawn("62", 'B', false, 'P'), "62");//pawn
	this->_BoardGrid[6][3] = Square(false, new Pawn("63", 'B', false, 'P'), "63");//pawn
	this->_BoardGrid[6][4] = Square(false, new Pawn("64", 'B', false, 'P'), "64");//pawn
	this->_BoardGrid[6][5] = Square(false, new Pawn("65", 'B', false, 'P'), "65");//pawn
	this->_BoardGrid[6][6] = Square(false, new Pawn("66", 'B', false, 'P'), "66");//pawn
	this->_BoardGrid[6][7] = Square(false, new Pawn("67", 'B', false, 'P'), "67");//pawn

	// setting up the eighth row
	this->_BoardGrid[7][0] = Square(false, new Rook("00", 'B', 'R'), "70"); // rook
	this->_BoardGrid[7][1] = Square(false, new Knight("01", 'B', 'N'), "71"); // knight
	this->_BoardGrid[7][2] = Square(false, new Bishop("02", 'B', 'B'), "72"); // bishop
	this->_BoardGrid[7][3] = Square(false, new King("03", 'B', 'K'), "73"); // king
	this->_BoardGrid[7][4] = Square(false, new Queen("04", 'B', 'Q'), "74"); // queen
	this->_BoardGrid[7][5] = Square(false, new Bishop("05", 'B', 'B'), "75"); // bishop
	this->_BoardGrid[7][6] = Square(false, new Knight("06", 'B', 'N'), "76"); // knight
	this->_BoardGrid[7][7] = Square(false, new Rook("07", 'B', 'R'), "77"); // rook


}

Board::~Board()
{
	this->_BoardGrid.clear();
}
Square Board::getSquare(int Yposition, int Xposition) const // get a squere at the board
{
	return this->_BoardGrid[Yposition][Xposition];
}
void Board::setSquareInBoard(Square mySquare, std::string position) // sets a specific Square at the board
{
	this->_BoardGrid[position[0]][position[1]] = mySquare;
}
