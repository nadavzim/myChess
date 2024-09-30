#include<string>
#pragma once
using namespace std; 

class Piece
{
public:
	bool alive = true;
protected:
	int xcor;
	int ycor;
	char key = '@';
	int pieceValue = 0;
	bool color = true;


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
	virtual Piece* clone() const = 0; // Pure virtual function for cloning
};
