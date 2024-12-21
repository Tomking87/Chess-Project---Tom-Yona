#include <iostream>
#include <string>
#include "Manager.h"
#include "Board.h"
#include "ChessPiece.h"
#include "Player.h"
#include "Square.h"

int main()
{
	Board ChessBoard;
	Player WhitePlayer('W', false);
	Player BlackPlayer('B', false);
	char firstPlayer = 'W';
	Manager GameManager('W', ChessBoard, WhitePlayer, BlackPlayer);
	



	return 0;
}