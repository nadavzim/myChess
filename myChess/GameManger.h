#pragma once
#include"Board.h"
#include"stack"

class GameManger
{
	bool turn = false;
	Board b;
	GameLogger logger;

	stack<Memento> piecesUndoStack;
	stack<Memento> piecesRedoStack;
	stack<Memento> capturedUndoStack;
	stack<Memento> capturedRedoStack;
protected:
	void init();
	void printBoard();
	bool validMoveCmdInput(const string& s);
	void printGameState();


public:
	GameManger() { init(); }
	bool makeMove(const string& move);
	Board getBoard() { return b; }

	// 3 deceleration's of function's of the "careTaker" in the Memento Design Pattern - control the flow of the states
	void saveState();
	void undo();
	void redo();

private:
	void clearRedoStacks();
	void restoreState(const Memento& piecesState, const Memento& capturedState);

};