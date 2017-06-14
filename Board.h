#pragma once
#include <iostream>

using namespace std;

class Board {
public:
	Board();
private:
	char coord[3][3];
	int turn = 1;
	int x = 1;
	int y = 1;
	void getInput();
	void fillBoard();
	void printBoard(int x, int y);
	bool spaceBad();
	bool checkWin();
	bool checkReplay();
};