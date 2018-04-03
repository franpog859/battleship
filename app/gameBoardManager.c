#include "gameBoardManager.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>

void setStartingGameBoard(GameBoard* gameBoard) {
	initializeGameBoard(gameBoard);
	for (int whichPlayer = 0; whichPlayer < numberOfPlayers; whichPlayer++) {
		setPlayersBoard(gameBoard, whichPlayer);
	}
}

void initializeGameBoard(GameBoard* gameBoard) {
	gameBoard->firstPlayerMove = true;
	gameBoard->numberOfTurn = 1;
	for (int i = 0; i < numberOfPlayers; i++) {
		for (int j = 0; j < boardSize; j++) {
			for (int k = 0; k < boardSize; k++) {
				gameBoard->ownBoard[i][j][k] = EMPTY;
				gameBoard->oponentBoard[i][j][k] = EMPTY;
			}
		}
	}
}

void setPlayersBoard(GameBoard* gameBoard, int whichPlayer) {
	Location* newLocation = malloc(sizeof(Location));
	for (int i = 0; i < numberOfShips; i++) {
		clearTerminal();
		printGameBoard(gameBoard->ownBoard, whichPlayer);
		chooseShipLocation(gameBoard, whichPlayer, newLocation);
		setShipLocation(gameBoard, whichPlayer, newLocation);
	}
	free(newLocation);
}

void printGameBoard(char board[2][10][10], int whichPlayer) {
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

void chooseShipLocation(GameBoard* gameBoard, int whichPlayer, Location* newLocation) { 
	do {
		initializeLocation(newLocation);
		getNewLocation(newLocation);
	} while (!isLocationOk());
}

void initializeLocation(Location* location) {
	location->col = 0;
	location->row = 0;
}

void getNewLocation(Location* newLocation) { 
	printf("\nType a location (e.g.: C8) for your new ship: ");
	scanf_s("%c", &newLocation->col);
	scanf_s("%d", &newLocation->row);
	newLocation->col = castColAsInt(newLocation->col);
	getchar();
}

int castColAsInt(int col) {
	if (col < 'a') {
		return col - 'A';
	}
	else {
		return col - 'a';
	}
}

bool isLocationOk() { //TODO Take care of all cases.
	return true;
}

void setShipLocation(GameBoard* gameBoard, int whichPlayer, Location* location) {
	gameBoard->ownBoard[whichPlayer][location->row][location->col] = SHIP;
}

void freeGameBoard(GameBoard* gameBoard) {
	free(gameBoard);
}