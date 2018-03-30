#ifndef GAMEBOARDMANAGER_H
#define GAMEBOARDMANAGER_H

#include <stdbool.h>

typedef struct GameBoard {
	char board[10][10];
	bool firstPlayerMove;
} GameBoard;

void freeGameBoard(GameBoard* gameBoard);

#endif // !GAMEBOARDMANAGER_H

