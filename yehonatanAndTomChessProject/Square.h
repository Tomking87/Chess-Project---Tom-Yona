#pragma once
// include ChessPiece

class Square
{
private:
	//ChessPiece _Piece;
	bool _isEmpty;
public:
	Square(bool isEmpty);
	~Square();
	bool getSquareStatus() const; // output is Empty
	void setSquareStatus(bool squareStatus); // input to isEmpty
};