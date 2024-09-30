#pragma once
#include"Pieces.h"

class Knight : public Piece
{
	char key = 'H';
public:
	Knight(int x, int y, bool color) : Piece(x, y, color) { pieceValue = 3; };
	char getKey() { return key; };
	bool validMove(int xDst, int yDst, bool isKill);
	string getIcon() override {
		return color ? "♘" : "♞"; // White knight: ♘, Black knight: ♞
	}
	Knight* clone() const override;
};

