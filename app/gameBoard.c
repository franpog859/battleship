#include "gameBoard.h"
#include <stdio.h>

void printBoard(char board[numberOfPlayers][boardSize][boardSize], int whichPlayer) {
	printf("The board of %d. player:\n\n", whichPlayer);
	printf("   A B C D E F G H I J\n\n");
	for (int i = 0; i < boardSize; i++) {
		printf("%d  ", i);
		for (int j = 0; j < boardSize; j++) {
			printf("%c ", board[whichPlayer][i][j]);
		}
		printf("\n");
	}
}