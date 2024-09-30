#include"Pieces.h"
#pragma once


class Bishop : public Piece
{
	char key = 'B';
public:
	Bishop(int x, int y, bool color) : Piece(x, y, color) { pieceValue = 3; };
	char getKey() { return key; };
	bool validMove(int xDst, int yDst, bool isKill);
	string getIcon() override {
		return color ? "♗" : "♝"; // White bishop: ♗, Black bishop: ♝
	}
	Bishop* clone() const override;

};

