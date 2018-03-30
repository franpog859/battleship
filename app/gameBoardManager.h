#ifndef GAMEBOARDMANAGER_H
#define GAMEBOARDMANAGER_H

#include <stdbool.h>

typedef struct GameBoard {
	char board[2][10][10]; //Two boards 10 x 10, one for each player.
	bool firstPlayerMove;
} GameBoard;

void freeGameBoard(GameBoard* gameBoard);

#endif

