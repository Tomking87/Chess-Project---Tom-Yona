///*
//This file servers as an example of how to use Pipe.h file.
//It is recommended to use the following code in your project, 
//in order to read and write information from and to the Backend
//*/
//
//#include "Pipe.h"
//#include <iostream>
//#include <thread>
//
//using std::cout;
//using std::endl;
//using std::string;
//
//
//void main()
//{
//	string moveCords = "";
//	string destinationSquare = "";
//	string sourceSquare = "";
//	Board ChessBoard;
//	string chessBoardString = "";
//	Player WhitePlayer('W', false);
//	Player BlackPlayer('B', false);
//	char firstPlayer = 'W';
//	Manager GameManager('W', ChessBoard, WhitePlayer, BlackPlayer);
//	GameManager.setCurrentTurn('W'); // white starts every game
//	int moveCode = 0;
//
//	srand(time_t(NULL));
//
//	
//	Pipe p;
//	bool isConnect = p.connect();
//	
//	string ans;
//	while (!isConnect)
//	{
//		cout << "cant connect to graphics" << endl;
//		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
//		std::cin >> ans;
//
//		if (ans == "0")
//		{
//			cout << "trying connect again.." << endl;
//			Sleep(2000);
//			isConnect = p.connect();
//		}
//		else 
//		{
//			p.close();
//			return;
//		}
//	}
//	
//
//	char msgToGraphics[1024];
//	// msgToGraphics should contain the board string accord the protocol
//	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0"); // just example...
//	
//	p.sendMessageToGraphics(msgToGraphics);   // send the board string
//
//	// get message from graphics
//	string msgFromGraphics = p.getMessageFromGraphics();
//
//	while (msgFromGraphics != "quit")
//	{		
//		sourceSquare = msgFromGraphics.substr(0, 2);
//		destinationSquare = msgFromGraphics.substr(2, 2);
//		sourceSquare = Manager::convertMoveIntoCords(sourceSquare);
//		destinationSquare = Manager::convertMoveIntoCords(destinationSquare);
//		string fullMove = sourceSquare + destinationSquare;
//
//		moveCode = GameManager.isMoveLeagal(fullMove, ChessBoard, msgFromGraphics);
//		if (moveCode == 0 || moveCode == 1 || moveCode == 8)
//		{
//			ChessBoard.updateBoard(fullMove);
//		}
//		GameManager.managePawnStatus(moveCode, destinationSquare, ChessBoard); // set pawn's status accordingly
//		
//		GameManager.managePawnStatus(moveCode, destinationSquare, ChessBoard); // set pawn's status accordingly
//		sprintf_s(msgToGraphics, sizeof(msgToGraphics), "%d", moveCode); // msgToGraphics should contain the result of the operation
//
//		///******* JUST FOR EREZ DEBUGGING ******/
//		//int r = rand() % 10; // just for debugging......
//		//msgToGraphics[0] = (char)(1 + '0');
//		//msgToGraphics[1] = 0;
//		///******* JUST FOR EREZ DEBUGGING ******/
//
//
//		// return result to graphics		
//		p.sendMessageToGraphics(msgToGraphics);   
//
//		// get message from graphics
//		msgFromGraphics = p.getMessageFromGraphics();
//
//		if (GameManager.getCurrentTurn() == 'W' && (moveCode == 0 || moveCode == 1 || moveCode == 8))
//		{
//			GameManager.setCurrentTurn('B');
//		}
//		else if (GameManager.getCurrentTurn() == 'B' && (moveCode == 0 || moveCode == 1 || moveCode == 8))
//		{
//			GameManager.setCurrentTurn('W');
//		}
//	}
//
//	p.close();
//}