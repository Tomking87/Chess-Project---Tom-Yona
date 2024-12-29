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
	string moveInput = "";
	string moveCords = "";
	string destinationSquare = "";
	string sourceSquare = "";
	Board ChessBoard;
	string chessBoardString = "";
	Player WhitePlayer('W', false);
	Player BlackPlayer('B', false);
	char firstPlayer = 'W';
	Manager GameManager('W', ChessBoard, WhitePlayer, BlackPlayer);
	GameManager.setCurrentTurn('W'); // white starts every game
	int moveCode = 0;

	std::string ascii_art = R"(
  /$$$$$$  /$$                                        ,....,
 /$$__  $$| $$                                       ,::::::<
| $$  \__/| $$$$$$$   /$$$$$$   /$$$$$$$  /$$$$$$$    ,::/^\"`.
| $$      | $$__  $$ /$$__  $$ /$$_____/ /$$_____/    ,::/,    e.
| $$      | $$  \ $$| $$$$$$$$|  $$$$$$ |  $$$$$$     ,::; |        '.
| $$    $$| $$  | $$| $$_____/ \____  $$ \____  $$    ,::|  \___,-.  c)
|  $$$$$$/| $$  | $$|  $$$$$$$ /$$$$$$$/ /$$$$$$$/    ;::|     \   '-'
 \______/ |__/  |__/ \_______/|_______/ |_______/     ;::|      \
                                                      ;::|   _.=\
                                                      ;:|.= _.=\
   By Tom and Yehonatan.                              '|_.=   __\
                                                        \_..== /
                                                       .'.___.-'.
                                                      /          \
                                                     ('--......--')
                                                     /'--......--'\
                                                      "--......--"
    )";

	std::cout << ascii_art << std::endl;

	while (true)
	{
		try
		{
			// display current turn
			if (GameManager.getCurrentTurn() == 'W')
			{
				cout << "		    Current Player: White" << endl;
			}
			else if (GameManager.getCurrentTurn() == 'B')
			{
				cout << "		    Current Player: Black" << endl;
			}

			chessBoardString = GameManager.convertBoardToString(ChessBoard);
			GameManager.printBoard(chessBoardString);

			// Input move
			cout << "Enter Move: ";
			cin >> moveInput;

			if (moveInput.length() == 4)
			{
				//convert move into source and destination cords
				sourceSquare = moveInput.substr(0, 2);
				destinationSquare = moveInput.substr(2, 2);
				sourceSquare = Manager::convertMoveIntoCords(sourceSquare);
				destinationSquare = Manager::convertMoveIntoCords(destinationSquare);
				string fullMove = sourceSquare + destinationSquare;
				cout << "full move: " << fullMove << endl;

				moveCode = GameManager.isMoveLeagal(fullMove, ChessBoard, moveInput); // need to add the check machanic
				cout << "move code: " << moveCode << endl;
				if (moveCode == 0 || moveCode == 1 || moveCode == 8)
				{
					ChessBoard.updateBoard(fullMove);
				}
				GameManager.managePawnStatus(moveCode, destinationSquare, ChessBoard); // set pawn's status accordingly
			}
			else
			{
				throw runtime_error("Invalid input must be 4 characters long");
			}
			cout << endl;

		}
		catch (const runtime_error& e)
		{
			std::cerr << e.what() << endl;
		}

		if (GameManager.getCurrentTurn() == 'W' && (moveCode == 0 || moveCode == 1 || moveCode == 8))
		{
			GameManager.setCurrentTurn('B');
		}
		else if (GameManager.getCurrentTurn() == 'B' && (moveCode == 0 || moveCode == 1 || moveCode == 8))
		{
			GameManager.setCurrentTurn('W');
		}

	}

	return 0;
}
