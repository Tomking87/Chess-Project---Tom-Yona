#include "Board.h"
using namespace std;

#define rowLength 8
#define colLength 8

Board::Board()
{
	_BoardGrid.resize(8, vector<Square>(8));

	for (int row = 0; row < rowLength; ++row) 
	{
		for (int col = 0; col < colLength; ++col) 
		{
			_BoardGrid[row][col] = Square(true, nullptr, to_string(row) + to_string(col));
		}
	}

	string zero = "0";

	// setting up the back rank
	this->_BoardGrid[0][0] = Square(false, new Rook("00", 'W', 'R'), "00"); // rook
	this->_BoardGrid[0][1] = Square(false, new Knight("01", 'W', 'N'), "01"); // knight
	this->_BoardGrid[0][2] = Square(false, new Bishop("02", 'W', 'B'), "02"); // bishop
	this->_BoardGrid[0][3] = Square(false, new King("03", 'W', 'K'), "03"); // king
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
	this->_BoardGrid[7][0] = Square(false, new Rook("70", 'B', 'R'), "70"); // rook
	this->_BoardGrid[7][1] = Square(false, new Knight("71", 'B', 'N'), "71"); // knight
	this->_BoardGrid[7][2] = Square(false, new Bishop("72", 'B', 'B'), "72"); // bishop
	this->_BoardGrid[7][3] = Square(false, new King("73", 'B', 'K'), "73"); // king
	this->_BoardGrid[7][4] = Square(false, new Queen("74", 'B', 'Q'), "74"); // queen
	this->_BoardGrid[7][5] = Square(false, new Bishop("75", 'B', 'B'), "75"); // bishop
	this->_BoardGrid[7][6] = Square(false, new Knight("76", 'B', 'N'), "76"); // knight
	this->_BoardGrid[7][7] = Square(false, new Rook("77", 'B', 'R'), "77"); // rook


}

Board::Board(std::vector<char> shuffle)
{
	string position = "";
	string zero = "0";
	string seven = "7";

	this->_BoardGrid.resize(8, vector<Square>(8));

	for (int row = 0; row < rowLength; ++row) 
	{
		for (int col = 0; col < colLength; ++col) 
		{
			this->_BoardGrid[row][col] = Square(true, nullptr, to_string(row) + to_string(col));
		}
	}
	
	for (int i = 0;i < colLength;i++)
	{
		if (shuffle[i] == 'R')
		{
			this->_BoardGrid[0][i] = Square(false, new Rook(zero+to_string(i), 'W', 'R'), zero + to_string(i)); // rook
		}
		else if (shuffle[i] == 'N')
		{
			this->_BoardGrid[0][i] = Square(false, new Knight(zero + to_string(i), 'W', 'N'), zero + to_string(i)); // knight
		}
		else if (shuffle[i] == 'B')
		{
			this->_BoardGrid[0][i] = Square(false, new Bishop(zero + to_string(i), 'W', 'B'), zero + to_string(i)); // bishop
		}
		else if (shuffle[i] == 'K')
		{
			this->_BoardGrid[0][i] = Square(false, new King(zero + to_string(i), 'W', 'K'), zero + to_string(i)); // king
		}
		else if (shuffle[i] == 'Q')
		{
			this->_BoardGrid[0][i] = Square(false, new Queen(zero + to_string(i), 'W', 'Q'), zero + to_string(i)); // queen
		}
	}

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

	// setting up black pawns
	this->_BoardGrid[6][0] = Square(false, new Pawn("60", 'B', false, 'P'), "60");//pawn
	this->_BoardGrid[6][1] = Square(false, new Pawn("61", 'B', false, 'P'), "61");//pawn
	this->_BoardGrid[6][2] = Square(false, new Pawn("62", 'B', false, 'P'), "62");//pawn
	this->_BoardGrid[6][3] = Square(false, new Pawn("63", 'B', false, 'P'), "63");//pawn
	this->_BoardGrid[6][4] = Square(false, new Pawn("64", 'B', false, 'P'), "64");//pawn
	this->_BoardGrid[6][5] = Square(false, new Pawn("65", 'B', false, 'P'), "65");//pawn
	this->_BoardGrid[6][6] = Square(false, new Pawn("66", 'B', false, 'P'), "66");//pawn
	this->_BoardGrid[6][7] = Square(false, new Pawn("67", 'B', false, 'P'), "67");//pawn
	
	//setting up the eight row
	for (int i = 0;i < colLength;i++)
	{
		if (shuffle[i] == 'R')
		{
			this->_BoardGrid[7][i] = Square(false, new Rook(seven + to_string(i), 'B', 'R'), seven + to_string(i)); // rook
		}
		else if (shuffle[i] == 'N')
		{
			this->_BoardGrid[7][i] = Square(false, new Knight(seven + to_string(i), 'B', 'N'), seven + to_string(i)); // knight
		}
		else if (shuffle[i] == 'B')
		{
			this->_BoardGrid[7][i] = Square(false, new Bishop(seven + to_string(i), 'B', 'B'), seven + to_string(i)); // bishop
		}
		else if (shuffle[i] == 'K')
		{
			this->_BoardGrid[7][i] = Square(false, new King(seven + to_string(i), 'B', 'K'), seven + to_string(i)); // king
		}
		else if (shuffle[i] == 'Q')
		{
			this->_BoardGrid[7][i] = Square(false, new Queen(seven + to_string(i), 'B', 'Q'), seven + to_string(i)); // queen
		}
	}
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
	this->_BoardGrid[int(position[0]) - 48][int(position[1]) - 48] = mySquare;
}

void Board::updateBoard(std::string moveString)
{
	std::string currPosition = std::string() + moveString[0] + moveString[1];
	std::string targetPosition = std::string() + moveString[2] + moveString[3];
	ChessPiece* myChessPiece = this->_BoardGrid[int(moveString[0]) - 48][int(moveString[1]) - 48].getChessPieceAtSquare();
	currPosition = std::string() + moveString[0] + moveString[1];
	targetPosition = std::string() + moveString[2] + moveString[3];
	this->_BoardGrid[int(moveString[0]) - 48][int(moveString[1]) - 48] = Square(true, nullptr, currPosition);
	this->_BoardGrid[int(moveString[2]) - 48][int(moveString[3]) - 48] = Square(false, myChessPiece, targetPosition);
	myChessPiece->setCords(int(moveString[2]) - 48, int(moveString[3]) - 48);
}