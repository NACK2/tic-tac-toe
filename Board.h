#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

class Board
{
	public:
		// prints tic tac toe board
		void printBoard();
	
	private:
		std::vector<std::vector<std::string>> values {
		{"1", "2", "3"},
		{"4", "5", "6"},
		{"7", "8", "9"}
		};
};

#endif BOARD_H

