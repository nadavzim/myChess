#include"Pieces.h"
#pragma once

class Pawn : public Piece
{
	bool moved = false;
	char key = 'P';
public:
	Pawn(int x, int y, bool color) : Piece(x, y, color) { pieceValue = 1; };
	char getKey() { return key; };
	bool validMove(int dstX, int dstY, bool);
	void setMoved() { moved = true; }
	string getIcon() override {
		return color ? "♙" : "♟"; // White pawn: ♙, Black pawn: ♟
	}
	Piece* clone() const override;
};

