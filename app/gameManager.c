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
	int lastTurnPlayer = gameBoard->activePlayer;
	if (gameBoard->pointsCounter[lastTurnPlayer] == numberOfShips) {
		return false;
	}
	return true;
}

void doTheTurn(GameBoard* gameBoard) { 
	changeActivePlayer(gameBoard); //WARNING: It must be at the beginning of this function.
	//TODO
}

void changeActivePlayer(GameBoard* gameBoard) {
	if (gameBoard->activePlayer == 0) {
		gameBoard->activePlayer = 1;
	}
	else {
		gameBoard->activePlayer = 0;
	}
}

void publicWinner(GameBoard* gameBoard) {
	int winner = getWinner(gameBoard);
	clearTerminal();
	printWinner(winner);
	pause();
}

int getWinner(GameBoard* gameBoard) { 
	return gameBoard->activePlayer;
}
