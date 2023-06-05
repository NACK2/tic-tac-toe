#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

class Board
{
	public:
		Board();

		// prints tic tac toe board
		void printBoard();

		// returns member variable isGameOver
		bool getIsGameOver();

		// sets member variable isGameOver
		void setIsGameOver(bool val);

		// returns the num'th value within values array
		std::string getValue(int num);

		// sets the num'th value in values array to input
		void setValue(int num, std::string input);
	
	private:
		// don't need a dynamic array (vector) as the size of array will stay same
		std::string values[9];
		bool isGameOver;
};

#endif BOARD_H

