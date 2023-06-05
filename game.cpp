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
	srand(time(0));
	int compPos = rand() % 9; // gives rand num between 0 and 8
	// TODO: add a draw/tie when board is full but no winner exists

	// keeps going until someone wins
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
		checkWinnerExists(board); // if winner exists, sets Board's isGameOver = true, causing loop to end
	}

	if (board.getIsGameOver()) {
		std::cout << "winner exists";
	}
	//else {
	//	std::cout << "ran out of spots, no winner\n";
	//}
}

void checkWinnerExists(Board &board) {
	int i = 0;
	int j = 0;
	while (i < 9) {
		if (board.getValue(i) == board.getValue(i + 1) && board.getValue(i + 1) == board.getValue(i + 2) && board.getValue(i) != " ") {
			board.setIsGameOver(true);
		}
		else if (board.getValue(j) == board.getValue(j + 3) && board.getValue(j + 3) == board.getValue(j + 6) && board.getValue(j) != " ") {
			board.setIsGameOver(true);
		}
		else if (board.getValue(0) == board.getValue(4) && board.getValue(4) == board.getValue(8) && board.getValue(0) != " ") {
			board.setIsGameOver(true);
		}
		else if (board.getValue(2) == board.getValue(4) && board.getValue(4) == board.getValue(6) && board.getValue(2) != " ") {
			board.setIsGameOver(true);
		}
		i += 3;
		j += 1;
	}
}