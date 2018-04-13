#include "gameManager.h"
#include "parameters.h"
#include "gameBoardManager.h"
#include "gameBoard.h"
#include "utils.h"
#include <stdbool.h>

void prepareAndPlay(Parameters* params) {
	GameBoard* gameBoard = malloc(sizeof(GameBoard));
	prepareGameBoard(gameBoard, params);
	
	while (isGameOn(gameBoard)) {
		doTheTurn(gameBoard);
	}

	publicWinner(gameBoard);
	free(gameBoard);
}

void prepareGameBoard(GameBoard* gameBoard, Parameters* params) {
	if (isGameLoaded(params)) {
		//loadGame(gameBoard);
	}
	else {
		setStartingGameBoard(gameBoard);
	}
}

bool isGameOn(GameBoard* gameBoard) {
	for (int i = 0; i < numberOfPlayers; i++) {
		if (gameBoard->pointsCounter[i] == numberOfShips) {
			return false;
		}
	}
	return true;
}

void doTheTurn(GameBoard* gameBoard) {
	return; //TODO
}

void publicWinner(GameBoard* gameBoard) {
	int winner = getWinner(gameBoard);
	clearTerminal();
	printf("The winner is player %d!", winner);
	pause();
}

int getWinner(GameBoard* gameBoard) {
	for (int i = 0; i < numberOfPlayers; i++) {
		if (gameBoard->pointsCounter[i] == numberOfShips) {
			return i;
		}
	}
	return -1; //If something went wrong.
}
