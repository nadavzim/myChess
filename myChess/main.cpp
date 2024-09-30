# include <iostream>
using namespace std;
#include"GameManger.h"
#include <windows.h>


void SetConsoleFontSize(int size);

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleFontSize(30);

	cout << "Enter \"-1\" to exit\n";
	string move = "\0";
	bool finished = false;
	GameManger game;
	cout << "please enter a move:\ncurrent piece location- x1y1 and destenation- x2y2\nfor exmple: e2e4\n";
	while (!finished)
	{
		cin >> move;
		if (move == "-1")
			return 0;
		else if (move == "z" || move == "Z")
			game.undo();
		else if (move == "y" || move == "Y")
			game.redo();
		else if (!game.makeMove(move))
			cout << "invalid move.\n";

	}
}


void SetConsoleFontSize(int size) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);

	// Get the current font information
	GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

	// Set the new font size
	fontInfo.dwFontSize.Y = size; // Adjust height (in pixels)
	fontInfo.dwFontSize.X = 0;     // Width will be calculated automatically
	SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
}