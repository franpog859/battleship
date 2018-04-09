#include "gameBoardManager.h"
#include "utils.h"
#include "gameBoard.h"
#include <stdio.h>

void printBoard(char board[2][10][10], int whichPlayer) {
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