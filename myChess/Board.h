#include<iostream>
#include <vector>
#include "PieceFactory.h"
#include "ChessObserver.h"
#include"GameLogger.h"
#include "BoardMemento.h"



using namespace std;
#pragma once
class Board
{
	int size = 8;
	vector<Piece*> wPieces;
	vector<Piece*> bPieces;
	vector<vector<Piece*>> pieces = { wPieces, bPieces };
	vector<ChessObserver*> observers;  // List of observers


public:
	void init();
	Piece* findPiece(char x, char y);
	bool makeMove(string src, string dst, bool turn);
	bool clearPath(int, int, int, int);
	void print();
	void registerObserver(ChessObserver* observer) { observers.push_back(observer);
	}
	void notifyPieceCaptured(Piece* capturedPiece);
	Memento saveState() const;
	void restoreState(const Memento& memento);


private:
	Piece* findPiece(int, int);
	void addPiece(char type, int x, int y, bool isWhite);
	unique_ptr<Piece> createPiece(char type, int x, int y, bool isWhite);
	int charToIndex(char) const;
};

