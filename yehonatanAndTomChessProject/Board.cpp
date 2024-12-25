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

	Rook whiteRookL("00", 'W', 'R');
	Rook whiteRookR("01", 'W', 'R');
	Knight whiteKnightL("02", 'W', 'N');
	Knight whiteKnightR("03", 'W', 'N');
	Bishop whiteBishopL("04", 'W', 'B');
	Bishop whiteBishopR("05", 'W', 'B');
	King whiteKing("06", 'W', 'K');
	King whiteQueen("07", 'W', 'Q');

	Pawn whitePawn1("10", 'W', false, 'P');
	Pawn whitePawn2("11", 'W', false, 'P');
	Pawn whitePawn3("12", 'W', false, 'P');
	Pawn whitePawn4("13", 'W', false, 'P');
	Pawn whitePawn5("14", 'W', false, 'P');
	Pawn whitePawn6("15", 'W', false, 'P');
	Pawn whitePawn7("16", 'W', false, 'P');
	Pawn whitePawn8("17", 'W', false, 'P');

	Rook blackRookL("70", 'B', 'R');
	Knight blackKnightL("71", 'B', 'N');
	Bishop blackBishopL("72", 'B', 'B');
	King blackKing("73", 'B', 'K');
	Queen blackQueen("74", 'B', 'Q');
	Bishop blackBishopR("75", 'B', 'B');
	Knight blackKnightR("76", 'B', 'N');
	Rook blackRookR("77", 'B', 'R');

	Pawn blackPawn1("60", 'B', false, 'P');
	Pawn blackPawn2("61", 'B', false, 'P');
	Pawn blackPawn3("62", 'B', false, 'P');
	Pawn blackPawn4("63", 'B', false, 'P');
	Pawn blackPawn5("64", 'B', false, 'P');
	Pawn blackPawn6("65", 'B', false, 'P');
	Pawn blackPawn7("66", 'B', false, 'P');
	Pawn blackPawn8("67", 'B', false, 'P');

	string zero = "0";

	//this->_BoardGrid[0][0] = Square(false, &whiteRookL, "00");//rook
	this->_BoardGrid[0][1] = Square(false, &whiteKnightL, "01");//knight
	this->_BoardGrid[0][2] = Square(false, &whiteBishopL, "02");//bishop
	//this->_BoardGrid[0][3] = Square(false, &whiteKing, "03");//King
	this->_BoardGrid[0][4] = Square(false, &whiteQueen, "04");//Queen
	this->_BoardGrid[0][5] = Square(false, &whiteBishopR, "05");//bishop
	this->_BoardGrid[0][6] = Square(false, &whiteKnightR, "06");//knight
	this->_BoardGrid[0][7] = Square(false, &whiteRookR, "07");//rook

	// Setting up the second row with white pawns
	this->_BoardGrid[1][0] = Square(false, &whitePawn1, "10");//pawn
	this->_BoardGrid[1][1] = Square(false, &whitePawn2, "11");//pawn
	this->_BoardGrid[1][2] = Square(false, &whitePawn3, "12");//pawn
	this->_BoardGrid[1][3] = Square(false, &whitePawn4, "13");//pawn
	this->_BoardGrid[1][4] = Square(false, &whitePawn5, "14");//pawn
	this->_BoardGrid[1][5] = Square(false, &whitePawn6, "15");//pawn
	this->_BoardGrid[1][6] = Square(false, &whitePawn7, "16");//pawn
	this->_BoardGrid[1][7] = Square(false, &whitePawn8, "17");//pawn


	// Setting up rows 2 to 5 (empty squares
	for (int i = 2; i < 6;i++)
	{
		for (int j = 0;j < rowLength;j++)
		{
			this->_BoardGrid[i][j] = Square(true, nullptr, to_string(i) + to_string(j));
		}
	}

	this->_BoardGrid[3][3] = Square(false, &whiteKing, "33");
	this->_BoardGrid[3][0] = Square(false, &whiteRookL, "30");
	// setting up the seventh row with black pawns
	this->_BoardGrid[6][0] = Square(false, &blackPawn1, "60");//pawn
	this->_BoardGrid[6][1] = Square(false, &blackPawn2, "61");//pawn
	this->_BoardGrid[6][2] = Square(false, &blackPawn3, "62");//pawn
	this->_BoardGrid[6][3] = Square(false, &blackPawn4, "63");//pawn
	this->_BoardGrid[6][4] = Square(false, &blackPawn5, "64");//pawn
	this->_BoardGrid[6][5] = Square(false, &blackPawn6, "65");//pawn
	this->_BoardGrid[6][6] = Square(false, &blackPawn7, "66");//pawn
	this->_BoardGrid[6][7] = Square(false, &blackPawn8, "67");//pawn

	// setting up the eighth row
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
