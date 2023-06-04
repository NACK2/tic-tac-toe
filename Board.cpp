#include <iostream>
#include <vector>
#include <string>
#include "Board.h"

Board::Board() {
	for (int i = 0; i < 9; ++i) {
			values[i] = " ";
	}
	isGameOver = false;
}

void Board::printBoard() {
	std::cout << " _____ _____ _____ \n";
	std::cout << "|     |     |     |\n";
	std::cout << "|  " 
	+ values[0] + "  |  "
	+ values[1] + "  |  "
	+ values[2] + "  |\n";
	std::cout << "|_____|_____|_____|\n";

	std::cout << "|     |     |     |\n";
	std::cout << "|  "
	+ values[3] + "  |  "
	+ values[4] + "  |  "
	+ values[5] + "  |\n";
	std::cout << "|_____|_____|_____|\n";

	std::cout << "|     |     |     |\n";
	std::cout << "|  "
	+ values[6] + "  |  "
	+ values[7] + "  |  "
	+ values[8] + "  |\n";
	std::cout << "|_____|_____|_____|\n";
}

bool Board::getIsGameOver() {
	return isGameOver;
}

std::string Board::getValue(int num) {
	return values[num];
}

void Board::setValue(int num, std::string input) {
	values[num] = input;
}
