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

// TODO: 
// 1) Ask player if they want to play again after finishing
// 2) Ask who wants to go first
// 3) TODO: When player is close to winning, computer should try to block player off
void startGame() {
	Board board;
	int pos = 0;
	srand(time(0));
	int compPos = rand() % 9; // gives rand num between 0 and 8
	int numTurns = 0;
	int winner = 0; // 0 = computer, 1 = player, 2 = tie

	while (true) {
		std::cout << "\n\nPick a position: \n";
		std::cin >> pos;
		while (board.getValue(pos-1) != " ") { // if player chooses a taken pos
			std::cout << "ERROR: That position is already taken, try again!\n";
			std::cout << "\n\nPick a position: \n";
			std::cin >> pos;
		}
		board.setValue(pos - 1, "X");
		board.printBoard();

		checkWinnerExists(board);
		if (board.getIsGameOver()) {
			winner = 1;
			break;
		}

		++numTurns;
		if (numTurns == 5) { // max amt of turns possible, if we reached here, means there wasn't a winner
			winner = 2;
			break;
		}

		while (board.getValue(compPos) != " ") { // keep looping until computer generates num that isn't taken
			compPos = rand() % 9;
		}
		std::cout << "\n\nComputer's turn!\n";
		board.setValue(compPos, "O");
		board.printBoard();

		checkWinnerExists(board); 
		if (board.getIsGameOver()) // don't need to do winner = 0 for computer winning, already set to 0 as default
			break;
	}

	switch (winner) {
		case (1):
			std::cout << "You Win!\n";
			break;
		case (2):
			std::cout << "Tie!\n";
			break;
		default:
			std::cout << "Computer Wins!\n";
			break;
	}
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