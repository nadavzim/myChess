#include<string>
#pragma once
using namespace std; 

class Piece
{
protected:
	int xcor;
	int ycor;
	char key = '@';
	int pieceValue = 0;
	bool color = true;
	bool alive = true;


public:
	Piece(int x, int y, bool color = true) { xcor = x, ycor = y, this->color = color; };
	int getxcor() { return xcor; }
	int getycor() { return ycor; }
	bool getycolor() { return color; }
	virtual char getKey() {	return key;}
	virtual bool validMove(int dstX, int dstY, bool isKill = false) { return this->validMove(dstX, dstY, isKill); };	// check if the move valid for the piece (regeardless to the board status)
	void move(int, int, bool isKill = false);
	virtual std::string getIcon() = 0; // Pure virtual to make the class abstract
	void setDead() { alive = false; xcor = -1; ycor = -1; }
	bool getAlive() { return alive; }
};

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
};

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
};

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
};

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
};

class King : public Piece
{
	char key = 'K';
public:
	King(int x, int y, bool color) : Piece(x, y, color){};
	char getKey() { return key; };
	bool validMove(int xDst, int yDst, bool isKill);
	string getIcon() override {
		return color ? "♔" : "♚"; // White king: ♔, Black king: ♚
	}
};