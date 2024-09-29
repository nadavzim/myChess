#pragma once
#include"Board.h"

class GameManger
{
	string gameLog = "";
	Board b;

protected:
	void init();
	void printBorard();
	bool valid__move_cmd_input(string);

public:
	GameManger() { init(); }
	bool makeMove(string, bool);
	Board getBoard() { return b; }

};

