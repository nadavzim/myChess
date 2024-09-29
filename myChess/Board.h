#include<iostream>
#include <vector>
#include"Pieces.h"
#include"Queen.h"



using namespace std;
#pragma once
class Board
{
	int size = 8;
	vector<Piece*> wPieces;
	vector<Piece*> bPieces;
	vector<vector<Piece*>> picecs = { wPieces, bPieces };

public:
	void init();
	Piece* findPiece(char x, char y);
	bool makeMove(string src, string dst, bool turn);
	bool clearPath(int, int, int, int);
	void print();

private:
	Piece* findPiece(int, int);
	void addPiece(char type, int x, int y, bool isWhite);
	int chrToInt(char);
};

