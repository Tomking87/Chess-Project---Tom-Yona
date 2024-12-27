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
	while (true)
	{
		try
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

			chessBoardString = GameManager.convertBoardToString(ChessBoard);
			//cout << chessBoardString << endl;
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

				Square mySquare = ChessBoard.getSquare(3, 5);
				cout << "Got square" << endl;
				if (mySquare.getChessPieceAtSquare() == nullptr) {
					cout << "Piece is null!" << endl;
				}
				else {
					cout << "Accessing piece..." << endl;
					ChessPiece* piece = mySquare.getChessPieceAtSquare();
					cout << piece->getChessPieceColor() << endl;
					cout << piece->getChessPieceType() << endl;
					cout << "got status stuff" << endl;
					vector<string> arrVec = piece->move(ChessBoard); // Store pointer to avoid multiple calls
					cout << "out of move" << endl;
					for (int i = 0;i < arrVec.size();i++)
					{
						cout << arrVec[i] << endl;
					}
					
				}
			}
			else
			{
				throw runtime_error("Invalid input");
			}
			cout << endl;

			cout << sourceSquare << endl; 
			cout << destinationSquare << endl;
			
		}
		catch (const runtime_error& e)
		{
			std::cerr << "Error: " << e.what() << endl;
		}
		
	}

	return 0;
}