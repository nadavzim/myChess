#pragma once
#include"Pieces.h"
class Queen : public Piece
{
	char key = 'Q';
public:
	Queen(int x, int y, bool color) : Piece(x, y, color) { pieceValue = 9; };
	char getKey() { return key; };
	bool validMove(int xDst, int yDst, bool isKill);
	string getIcon() override {
		return color ? "♕" : "♛"; // White queen: ♕, Black queen: ♛
	}
	Queen* clone() const override;

};
