#ifndef GAME_H
#define GAME_H

#include "Board.h"

// Explain the game before starting
void gameExplain();

// start the game
void startGame();

// check if some has won (make sure to PASS BY REF to affect the actual board)
void checkWinnerExists(Board &board);

#endif GAME_H
