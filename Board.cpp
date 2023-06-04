#include <iostream>
#include <vector>
#include "Board.h"

void Board::printBoard() {
	std::cout << " _____ _____ _____ \n";
	std::cout << "|     |     |     |\n";
	std::cout << "|  " 
	+ values[0][0] + "  |  "
	+ values[0][1] + "  |  "
	+ values[0][2] + "  |\n";
	std::cout << "|_____|_____|_____|\n";

	std::cout << "|     |     |     |\n";
	std::cout << "|  "
	+ values[1][0] + "  |  "
	+ values[1][1] + "  |  "
	+ values[1][2] + "  |\n";
	std::cout << "|_____|_____|_____|\n";

	std::cout << "|     |     |     |\n";
	std::cout << "|  "
	+ values[2][0] + "  |  "
	+ values[2][1] + "  |  "
	+ values[2][2] + "  |\n";
	std::cout << "|_____|_____|_____|\n";

}
