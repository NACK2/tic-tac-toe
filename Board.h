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
		// don't need a dynamic array (vector) as the size of 2d array will stay same
		std::string values[3][3] = {
		{"1", "2", "3"},
		{"4", "5", "6"},
		{"7", "8", "9"}
		};
};

#endif BOARD_H

