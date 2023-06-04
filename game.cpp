#include <iostream>
#include <cstdlib>
#include "game.h"
#include "Board.h"

void gameExplain() {
	std::cout << "Welcome to Tic Tac Toe! You get to make the first move!\n";
	std::cout << "The top left corner is position 1, and the bottom left corner is position 9:\n";

	// printing board with numbers valued 1 to 9 to show user the positioning scheme
	Board board;
	for (int i = 0; i < 9; ++i) {
		board.setValue(i, std::to_string(i+1));
	}
	board.printBoard();
	std::cout << "Good luck!\n";

	startGame();
}

void startGame() {
	Board board;
	int pos = 0;

	// TODO: FIX RAND, the computer keeps generating the SAME sequence of rand numbers
	int compPos = rand() % 9; // gives rand num between 0 and 8

	// keeps going until someone wins
	// TODO: create condition so that getIsGameOver = true is possible
	while (!board.getIsGameOver()) {
		std::cout << "\n\nPick a position: \n";
		std::cin >> pos;
		while (board.getValue(pos-1) != " ") {
			std::cout << "ERROR: That position is already taken, try again!\n";
			std::cout << "\n\nPick a position: \n";
			std::cin >> pos;
		}
		board.setValue(pos - 1, "X");
		board.printBoard();

		// keep looping until computer generates num that isn't taken
		while (board.getValue(compPos) != " ") {
			compPos = rand() % 9; // gives rand num between 0 and 8
		}
		std::cout << "\n\nComputer's turn!\n";
		board.setValue(compPos, "O");
		board.printBoard();
	}
}