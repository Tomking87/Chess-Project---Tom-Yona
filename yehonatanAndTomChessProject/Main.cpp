#include <iostream>
#include <string>
#include "Manager.h"
#include "Board.h"
#include "ChessPiece.h"
#include "Player.h"
#include "Square.h"
#include <thread>
#include "FrontEndGraphicsInterafce/Pipe.h"
#include <cstring>

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
	int InterfaceChoice = 0;
	int GameChoice = 0;

	Manager::printASCII(0);

	cout << "Choose Your GameMode:" << endl;
	cout << "Classical Chess - 0" << endl;
	cout << "Ficher Random - 1" << endl;
	cin >> GameChoice;

	// Pick a Game
	if (GameChoice == 1)
	{
		cout << "The Board's back ranks will now be Shuffled." << endl << endl;
		std::vector<char> shuffleOrder = Manager::shuffle(); // shuffle pieces
		Board FicherRndChessBoard(shuffleOrder); // create board
		ChessBoard = FicherRndChessBoard; // cast board
	}
	
	// Pick an Inteface
	cout << "Choose Your Inteface:" << endl;
	cout << "Graphics(GUI) - 0" << endl;
	cout << "Console - 1" << endl;
	cin >> InterfaceChoice;
	if (InterfaceChoice == 0)
	{
		srand(time_t(NULL));

		Pipe p;
		bool isConnect = p.connect();

		string ans;
		while (!isConnect)
		{
			cout << "cant connect to graphics" << endl;
			cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
			std::cin >> ans;

			if (ans == "0")
			{
				cout << "trying connect again.." << endl;
				Sleep(2000);
				isConnect = p.connect();
			}
			else
			{
				p.close();
				return 0;
			}
		}

		char msgToGraphics[1024];
		if (GameChoice == 0)
		{
			// msgToGraphics should contain the board string accord the protocol
			strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0");
		}
		else if (GameChoice == 1)
		{
			// msgToGraphics Ficher random
			string myBoardStr = GameManager.convertBoardToString(ChessBoard);
			string result;
			result.reserve(64);
			result += myBoardStr.substr(56, 8);  // Characters 57-64
			result += myBoardStr.substr(48, 8);  // Characters 49-56
			result += myBoardStr.substr(16, 32); // Characters 17-48
			result += myBoardStr.substr(8, 8);   // Characters 9-16
			result += myBoardStr.substr(0, 8);   // Characters 1-8
			result += "0"; // White Begins
			strcpy_s(msgToGraphics, sizeof(msgToGraphics), result.c_str());
		}

		p.sendMessageToGraphics(msgToGraphics);   // send the board string

		// get message from graphics
		string msgFromGraphics = p.getMessageFromGraphics();

		while (msgFromGraphics != "quit")
		{
			sourceSquare = msgFromGraphics.substr(0, 2);
			destinationSquare = msgFromGraphics.substr(2, 2);
			sourceSquare = Manager::convertMoveIntoCords(sourceSquare);
			destinationSquare = Manager::convertMoveIntoCords(destinationSquare);
			string fullMove = sourceSquare + destinationSquare;

			moveCode = GameManager.isMoveLeagal(fullMove, ChessBoard, msgFromGraphics);
			if (moveCode == 0 || moveCode == 1 || moveCode == 8)
			{
				ChessBoard.updateBoard(fullMove);
			}
			GameManager.managePawnStatus(moveCode, destinationSquare, ChessBoard); // set pawn's status accordingly

			GameManager.managePawnStatus(moveCode, destinationSquare, ChessBoard); // set pawn's status accordingly
			sprintf_s(msgToGraphics, sizeof(msgToGraphics), "%d", moveCode); // msgToGraphics should contain the result of the operation

			// return result to graphics		
			p.sendMessageToGraphics(msgToGraphics);

			// get message from graphics
			msgFromGraphics = p.getMessageFromGraphics();

			if (GameManager.getCurrentTurn() == 'W' && (moveCode == 0 || moveCode == 1 || moveCode == 8))
			{
				GameManager.setCurrentTurn('B');
			}
			else if (GameManager.getCurrentTurn() == 'B' && (moveCode == 0 || moveCode == 1 || moveCode == 8))
			{
				GameManager.setCurrentTurn('W');
			}
		}

		p.close();
	}
	else if (InterfaceChoice == 1)
	{
		

		while (true)
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

			//convert move into source and destination cords
			sourceSquare = moveInput.substr(0, 2);
			destinationSquare = moveInput.substr(2, 2);
			sourceSquare = Manager::convertMoveIntoCords(sourceSquare);
			destinationSquare = Manager::convertMoveIntoCords(destinationSquare);
			string fullMove = sourceSquare + destinationSquare;

			moveCode = GameManager.isMoveLeagal(fullMove, ChessBoard, moveInput); // need to add the check machanic

			if (moveCode == 0)
			{
				cout << "Valid Move" << endl;
			}
			else if (moveCode == 1)
			{
				cout << "Valid Move - You made Check" << endl;
			}
			else if (moveCode == 2)
			{
				cout << "Invalid Move - Not your player" << endl;
			}
			else if (moveCode == 3)
			{
				cout << "Invalid Move - Destination is not free" << endl;
			}
			else if (moveCode == 4)
			{
				cout << "Invalid Move - Check will Occur" << endl;
			}
			else if (moveCode == 5)
			{
				cout << "Invalid Move - Ileagal Square indexs" << endl;
			}
			else if (moveCode == 6)
			{
				cout << "Invalid Move - Ileagal Movement with Piece" << endl;
			}
			else if (moveCode == 7)
			{
				cout << "Invalid Move - Source and Destination Squares are the Same" << endl;
			}
			else if (moveCode == 8)
			{
				cout << "Valid Move - CheckMate!" << endl;
				Manager::printASCII(1);
				if (GameManager.getCurrentTurn() == 'W')
				{
					cout << "  White Wins." << endl;
				}
				else if (GameManager.getCurrentTurn() == 'B')
				{
					cout << "  Black Wins." << endl;
				}

				return 0;
			}

			if (moveCode == 0 || moveCode == 1 || moveCode == 8)
			{
				ChessBoard.updateBoard(fullMove);
				GameManager.managePawnStatus(moveCode, destinationSquare, ChessBoard); // set pawn's status accordingly
				GameManager.promotion(ChessBoard);
			}

			cout << endl;

			if (GameManager.getCurrentTurn() == 'W' && (moveCode == 0 || moveCode == 1 || moveCode == 8))
			{
				GameManager.setCurrentTurn('B');
			}
			else if (GameManager.getCurrentTurn() == 'B' && (moveCode == 0 || moveCode == 1 || moveCode == 8))
			{
				GameManager.setCurrentTurn('W');
			}

		}
	}
	else
	{
		cout << "Invalid Choice" << endl;
		return 0;
	}

	return 0;
}
