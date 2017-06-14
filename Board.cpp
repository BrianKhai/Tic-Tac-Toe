#include "Board.h"
#include <iostream>

Board::Board() {
	bool done = false;
	while (!done) {
		fillBoard();
		while (!done) {
			getInput();
			printBoard(x, y);

			if (checkWin()) {
				done = true;
				if (turn % 2 == 0) {
					cout << "X wins!\n";
				} else if (turn % 2 == 1) {
					cout << "O wins!\n";
				}
			}
			else if (turn > 9) {
				done = true;
				cout << "Draw!\n";
			}
		}
		if (checkReplay()) {
			done = false;
			turn = 1;
		}
	}
}

void Board::fillBoard() {
	for (int i = 0; i < 3; i++) {
		cout << "+-+-+-+" << endl;
		for (int j = 0; j < 3; j++) {
			coord[i][j] = ' ';
			cout << '|' << coord[i][j];
		}
		cout << '|' << endl;
	}
	cout << "+-+-+-+" << endl;
}

void Board::getInput() {
	if (turn % 2 == 1) {
		cout << "It's X's turn!\n";
	}
	else {
		cout << "It's O's turn!\n";
	}
	cout << "Input X Coordinate: ";
	cin >> x;
	cout << "Input Y Coordinate: ";
	cin >> y;

	if (x >= 1 && x <= 3 && y >= 1 && y <= 3) {
		if (spaceBad()) {
			cout << "That space is occupied!\n";
			getInput();
		}
	} else {
		cout << "Only numbers between 1-3 are valid--\n";
		getInput();
	}
}

void Board::printBoard(int x, int y) {
	if (turn % 2 == 1) {
		coord[x - 1][y - 1] = 'X';
	} else {
		coord[x - 1][y - 1] = 'O';
	}

	for (int i = 0; i < 3; i++) {
		cout << "+-+-+-+" << endl;
		for (int j = 0; j < 3; j++) {
			cout << '|' << coord[j][i];
		}
		cout << '|' << endl;
	}
	cout << "+-+-+-+" << endl;

	
	turn++;
}

bool Board::spaceBad() {
	if (coord[x - 1][y - 1] != ' ') {
		return true;
	} else {
		return false;
	}
}

bool Board::checkWin() {
	
	if (coord[0][0] == coord[0][1] && coord[0][0] == coord[0][2] && coord[0][0] != ' ') {
		return true;
	}
	if (coord[1][0] == coord[1][1] && coord[1][0] == coord[1][2] && coord[1][0] != ' ') {
		return true;
	}
	if (coord[2][0] == coord[2][1] && coord[2][0] == coord[2][2] && coord[2][0] != ' ') {
		return true;
	}

	if (coord[0][0] == coord[1][0] && coord[0][0] == coord[2][0] && coord[0][0] != ' ') {
		return true;
	}
	if (coord[0][1] == coord[1][1] && coord[0][1] == coord[2][1] && coord[0][1] != ' ') {
		return true;
	}
	if (coord[0][2] == coord[1][2] && coord[0][2] == coord[2][2] && coord[0][2] != ' ') {
		return true;
	}

	if (coord[0][0] == coord[1][1] && coord[0][0] == coord[2][2] && coord[0][0] != ' ') {
		return true;
	}
	if (coord[2][0] == coord[1][1] && coord[2][0] == coord[0][2] && coord[2][0] != ' ') {
		return true;
	}

	return false;
}


bool Board::checkReplay() {
	char input;
	bool badInput = true;
	while (badInput) {
		system("PAUSE");
		system("CLS");
		cout << "Would you like to play again? ([Y]es/[N]o)\n";
		cin >> input;
		if (input == 'y' || input == 'Y') {
			cout << "Starting new game!\n";
			bool badInput = false;
			return true;
		} else if (input == 'n' || input == 'N') {
			cout << "Good game!\n";
			bool badInput = false;
			return false;
		} else {
			cout << "Please input a valid response!\n";
		}
	}
}