#include <iostream>
#include <string>
#include "Manager.h"
#include "Board.h"
#include "ChessPiece.h"
#include "Player.h"
#include "Square.h"

using namespace std;

int main()
{
	Board ChessBoard;
	string chessBoardString = "";
	Player WhitePlayer('W', false);
	Player BlackPlayer('B', false);
	char firstPlayer = 'W';
	Manager GameManager('W', ChessBoard, WhitePlayer, BlackPlayer);
	
	chessBoardString = GameManager.convertBoardToString(ChessBoard);
	cout << chessBoardString << endl;
	/*GameManager.printBoard(chessBoardString);*/

	return 0;
}