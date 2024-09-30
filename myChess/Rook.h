#include"Pieces.h"
#pragma once

class Rook : public Piece
{
	char key = 'R';
public:
	Rook(int x, int y, bool color) : Piece(x, y, color) { pieceValue = 5; };
	char getKey() { return key; };
	bool validMove(int xDst, int yDst, bool isKill);
	string getIcon() override {
		return color ? "♖" : "♜"; // White rook: ♖, Black rook: ♜
	}
	Rook* clone() const override;

};
