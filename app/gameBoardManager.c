#include "gameBoardManager.h"
#include "utils.h"
#include <stdbool.h>

void setPlayersGameBoards(GameBoard* gameBoard) {
	initializeGameBoard(gameBoard);
	//Set each game board.
}

void initializeGameBoard(GameBoard* gameBoard) {
	gameBoard->firstPlayerMove = true;
	for (int i = 0; i < numberOfPlayers; i++) {
		for (int j = 0; j < boardSize; j++) {
			for (int k = 0; k < boardSize; k++) {
				gameBoard->board[i][j][k] = EMPTY;
			}
		}
	}
}

void freeGameBoard(GameBoard* gameBoard) {
	free(gameBoard);
}