#include "GameManger.h"


void GameManger::init()
{
	b.init();
}

void GameManger::printBorard()
{
	b.print();
}

bool GameManger::valid__move_cmd_input(string s) {
	if (s[1] >= '1' && s[1] <= '8')
		if (s[0] >= 'A' && s[0] <= 'H')
			return true;
	return false;
}

//bool GameManger::valid_move(string src, string dst, bool turn)
//{
//	bool sucseed = false;
//	Piece* p = nullptr;
//	sucseed = b.makeMove(src, dst, turn);
//	return false;
//}

bool GameManger::makeMove(string move, bool turn)
{
	if (move.size() != 4)
		return false;
	move[0] = toupper(move[0]);
	move[2] = toupper(move[2]);
	string src = move.substr(0, 2);
	string dst = move.substr(2, 4);
	if (valid__move_cmd_input(src) && valid__move_cmd_input(dst))
	{
		bool res = b.makeMove(src, dst, turn);
		printBorard();
		return res;
	}
	return false;
}
