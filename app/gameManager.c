#include "gameManager.h"
#include "parameters.h"
#include "gameBoard.h"
#include "utils.h"
#include "inputChecker.h"
#include <stdbool.h>

void prepareAndPlay(Parameters* params) {
	GameBoard* gameBoard = (GameBoard*) malloc(sizeof(GameBoard));
	prepareGameBoard(gameBoard, params);
	
	while (isGameOn(gameBoard)) {
		incrementNumberOfTurns(gameBoard);
		doTheTurn(gameBoard);
	}

	publicWinner(gameBoard);
	free(gameBoard);
}

void prepareGameBoard(GameBoard* gameBoard, Parameters* params) {
	if (isGameLoaded(params)) {
		//TODO: loadGame(gameBoard);
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

void incrementNumberOfTurns(GameBoard* gameBoard) {
	if (gameBoard->activePlayer == 1) {
		gameBoard->numberOfTurns++;
	}
}

void publicWinner(GameBoard* gameBoard) {
	int winner = getWinner(gameBoard);
	clearTerminal();
	printWinner(winner);
	pause();
}

int getWinner(GameBoard* gameBoard) { 
	int lastTurnPlayer = gameBoard->activePlayer;
	return lastTurnPlayer;
}
