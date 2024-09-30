#include"Pieces.h"
#pragma once

class King : public Piece
{
	char key = 'K';
public:
	King(int x, int y, bool color) : Piece(x, y, color) {};
	char getKey() { return key; };
	bool validMove(int xDst, int yDst, bool isKill);
	string getIcon() override {
		return color ? "♔" : "♚"; // White king: ♔, Black king: ♚
	}
	King* clone() const override;

};