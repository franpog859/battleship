#ifndef GAMEBOARDMANAGER_H
#define GAMEBOARDMANAGER_H

#include <stdbool.h>

#define numberOfPlayers 2
#define boardSize 10

#define EMPTY '`'

typedef struct GameBoard {
	char board[2][10][10]; //Two boards 10 x 10, one for each player.
	bool firstPlayerMove;
} GameBoard;

void setPlayersGameBoards(GameBoard* gameBoard);

void initializeGameBoard(GameBoard* gameBoard);

void freeGameBoard(GameBoard* gameBoard);

#endif

