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
	Location* moveLocation = (Location*) malloc(sizeof(Location));
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
		increasePlayersPoints(gameBoard);
	}
}

void setMissingMove(GameBoard* gameBoard, Location* location) {
	gameBoard->oponentBoard[gameBoard->activePlayer][location->row][location->col] = WATER;
}

void setKillingMove(GameBoard* gameBoard, Location* location) {
	gameBoard->oponentBoard[gameBoard->activePlayer][location->row][location->col] = NOT_KILLED_SHIP;

	if (isEntirelyKilled(gameBoard, location, location)) {
		killEntireShip(gameBoard, location); 
	}
}

bool isEntirelyKilled(GameBoard* gameBoard, Location* actualLocation, Location* previousLocation) {
	Location* probeLocation = (Location*) malloc(sizeof(Location));
	bool isEntirelyKilledTemp = true;

	initializeProbeLocation(probeLocation, actualLocation->col + 1, actualLocation->row);
	isEntirelyKilledTemp = checkForProbeLocation(gameBoard, isEntirelyKilledTemp, 
		probeLocation, actualLocation, previousLocation);
	
	initializeProbeLocation(probeLocation, actualLocation->col - 1, actualLocation->row);
	isEntirelyKilledTemp = checkForProbeLocation(gameBoard, isEntirelyKilledTemp, 
		probeLocation, actualLocation, previousLocation);

	initializeProbeLocation(probeLocation, actualLocation->col, actualLocation->row + 1);
	isEntirelyKilledTemp = checkForProbeLocation(gameBoard, isEntirelyKilledTemp, 
		probeLocation, actualLocation, previousLocation);
	
	initializeProbeLocation(probeLocation, actualLocation->col, actualLocation->row - 1);
	isEntirelyKilledTemp = checkForProbeLocation(gameBoard, isEntirelyKilledTemp, 
		probeLocation, actualLocation, previousLocation);
	
	free(probeLocation);
	return isEntirelyKilledTemp;
}

void initializeProbeLocation(Location* probeLocation, int col, int row) {
	probeLocation->col = col;
	probeLocation->row = row;
}

bool checkForProbeLocation(GameBoard* gameBoard, bool isEntirelyKilledTemp,
	Location* probeLocation, Location* actualLocation, Location* previousLocation) {
	if ((probeLocation->col != previousLocation->col || probeLocation->row != previousLocation->row) &&
		isThereShip(gameBoard, probeLocation)) {
		if (!isEntirelyKilled(gameBoard, probeLocation, actualLocation)) {
			isEntirelyKilledTemp = false;
		}
	}
	if (!isLocationKilled(gameBoard, probeLocation)) {
		isEntirelyKilledTemp = false;
	}
	return isEntirelyKilledTemp;
}

bool isThereShip(GameBoard* gameBoard, Location* location) {
	int oponent = getOponent(gameBoard);
	if (location->col >= 0 &&
		location->col <= 9 &&
		location->row >= 0 &&
		location->row <= 9 &&
		gameBoard->ownBoard[oponent][location->row][location->col] == OWN_SHIP) {
		return true;
	}
	return false;
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

void killEntireShip(GameBoard* gameBoard, Location* location) {
	Location* probeLocation = (Location*) malloc(sizeof(Location)); 
	gameBoard->oponentBoard[gameBoard->activePlayer][location->row][location->col] = KILLED_SHIP;
	
	initializeProbeLocation(probeLocation, location->col + 1, location->row);
	if (isNotKilledShip(gameBoard, probeLocation)) 
		killEntireShip(gameBoard, probeLocation);

	initializeProbeLocation(probeLocation, location->col - 1, location->row);
	if (isNotKilledShip(gameBoard, probeLocation)) 
		killEntireShip(gameBoard, probeLocation);

	initializeProbeLocation(probeLocation, location->col, location->row + 1);
	if (isNotKilledShip(gameBoard, probeLocation)) 
		killEntireShip(gameBoard, probeLocation);

	initializeProbeLocation(probeLocation, location->col, location->row - 1);
	if (isNotKilledShip(gameBoard, probeLocation)) 
		killEntireShip(gameBoard, probeLocation);
	
	free(probeLocation);
}

bool isNotKilledShip(GameBoard* gameBoard, Location* probeLocation) {
	if (probeLocation->col >= 0 &&
		probeLocation->col <= 9 &&
		probeLocation->row >= 0 &&
		probeLocation->row <= 9 &&
		gameBoard->oponentBoard[gameBoard->activePlayer][probeLocation->row][probeLocation->col] == NOT_KILLED_SHIP) {
		return true;
	}
	return false;
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
