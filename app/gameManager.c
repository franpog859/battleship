#include "gameManager.h"
#include "parameters.h"
#include "gameBoard.h"
#include "utils.h"
#include "inputChecker.h"
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

void doTheTurn(GameBoard* gameBoard) { 
	Location* moveLocation = malloc(sizeof(Location));
	changeActivePlayer(gameBoard); //WARNING: It must be at the beginning of this function.
	clearTerminal();
	printBoard(gameBoard->oponentBoard, gameBoard->activePlayer);

	getMove(gameBoard, moveLocation);
	setMove(gameBoard, moveLocation);

	clearTerminal();
	printBoard(gameBoard->oponentBoard, gameBoard->activePlayer);
	secondSleep();

	free(moveLocation);
}

void changeActivePlayer(GameBoard* gameBoard) {
	gameBoard->activePlayer = getOponent(gameBoard);
}

int getOponent(GameBoard* gameBoard) {
	if (gameBoard->activePlayer == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void getMove(GameBoard* gameBoard, Location* moveLocation) {
	do {
		initializeLocation(moveLocation);
		getNewLocation(moveLocation);
	} while (!isLocationValid(gameBoard->oponentBoard, gameBoard->activePlayer, moveLocation));
}

void setMove(GameBoard* gameBoard, Location* location) {
	int oponent = getOponent(gameBoard);
	if (gameBoard->ownBoard[oponent][location->row][location->col] == EMPTY) {
		setMissingMove(gameBoard, location);
	}
	else {
		setKillingMove(gameBoard, location);
	}
}

void setMissingMove(GameBoard* gameBoard, Location* location) {
	gameBoard->oponentBoard[gameBoard->activePlayer][location->row][location->col] = WATER;
}

void setKillingMove(GameBoard* gameBoard, Location* location) {
	if (isEntirelyKilled(gameBoard, location)) {
		gameBoard->oponentBoard[gameBoard->activePlayer][location->row][location->col] = KILLED_SHIP;
		//TODO: It should kill entire ship recursively.
	}
	else {
		gameBoard->oponentBoard[gameBoard->activePlayer][location->row][location->col] = NOT_KILLED_SHIP;
	}
	
	increasePlayersPoints(gameBoard);
}

bool isEntirelyKilled(GameBoard* gameBoard, Location* location) {
	Location* probeLocation = malloc(sizeof(Location));
	bool isEntirelyKilled = true;

	initializeProbeLocation(probeLocation, location->col + 1, location->row);
	if (!isLocationKilled(gameBoard, probeLocation)) isEntirelyKilled = false;

	initializeProbeLocation(probeLocation, location->col - 1, location->row);
	if (!isLocationKilled(gameBoard, probeLocation)) isEntirelyKilled = false;

	initializeProbeLocation(probeLocation, location->col, location->row + 1);
	if (!isLocationKilled(gameBoard, probeLocation)) isEntirelyKilled = false;

	initializeProbeLocation(probeLocation, location->col, location->row - 1);
	if (!isLocationKilled(gameBoard, probeLocation)) isEntirelyKilled = false;
	
	free(probeLocation);
	return isEntirelyKilled;
}

void initializeProbeLocation(Location* probeLocation, int col, int row) {
	probeLocation->col = col;
	probeLocation->row = row;
}

bool isLocationKilled(GameBoard* gameBoard, Location* probeLocation) {
	int oponent = getOponent(gameBoard);
	if (probeLocation->col >= 0 &&
		probeLocation->col <= 9 &&
		probeLocation->row >= 0 &&
		probeLocation->row <= 9 &&
		gameBoard->oponentBoard[gameBoard->activePlayer][probeLocation->row][probeLocation->col] == EMPTY &&
		gameBoard->ownBoard[oponent][probeLocation->row][probeLocation->col] == OWN_SHIP) {
		return false;
	}
	return true;
}

void increasePlayersPoints(GameBoard* gameBoard) {
	gameBoard->pointsCounter[gameBoard->activePlayer]++;
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
