#include "turn.h"
#include "gameBoard.h"
#include "terminal.h"
#include "inputChecker.h"
#include <stdbool.h>

void doTheTurn(GameBoard* gameBoard) {
	Location moveLocation;
	changeActivePlayer(gameBoard); //WARNING: It must be at the beginning of this function.
	
	getMove(gameBoard, &moveLocation);
	if (isExitParam(gameBoard->params)) {
		changeActivePlayer(gameBoard); //It is important for saving part.
		return;
	}
	setMove(gameBoard, &moveLocation);

	clearTerminal();
	printBoard(gameBoard->oponentBoard, gameBoard->activePlayer);
	twoSecondsSleep();
}

void changeActivePlayer(GameBoard* gameBoard) {
	gameBoard->activePlayer = getOponent(gameBoard);
}

int getOponent(GameBoard* gameBoard) {
	return (gameBoard->activePlayer == 0) ? 1 : 0;
}

void getMove(GameBoard* gameBoard, Location* moveLocation) {
	do {
		clearTerminal();
		printBoard(gameBoard->oponentBoard, gameBoard->activePlayer);

		initializeLocation(moveLocation);
		getNewLocation(moveLocation, gameBoard->params);
	} while (!isLocationValid(gameBoard->oponentBoard, gameBoard->activePlayer, moveLocation) && 
		!isExitParam(gameBoard->params));
}

void setMove(GameBoard* gameBoard, Location* location) {
	int oponent = getOponent(gameBoard);
	if (gameBoard->ownBoard[oponent][location->row][location->col] == EMPTY)
		setMissingMove(gameBoard, location);
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

	if (isEntirelyKilled(gameBoard, location, location))
		killEntireShip(gameBoard, location);
}

bool isEntirelyKilled(GameBoard* gameBoard, Location* actualLocation, Location* previousLocation) {
	Location probeLocation;
	bool isEntirelyKilledTemp = true;

	initializeProbeLocation(&probeLocation, actualLocation->col + 1, actualLocation->row);
	isEntirelyKilledTemp = checkForProbeLocation(gameBoard, isEntirelyKilledTemp,
		&probeLocation, actualLocation, previousLocation);

	initializeProbeLocation(&probeLocation, actualLocation->col - 1, actualLocation->row);
	isEntirelyKilledTemp = checkForProbeLocation(gameBoard, isEntirelyKilledTemp,
		&probeLocation, actualLocation, previousLocation);

	initializeProbeLocation(&probeLocation, actualLocation->col, actualLocation->row + 1);
	isEntirelyKilledTemp = checkForProbeLocation(gameBoard, isEntirelyKilledTemp,
		&probeLocation, actualLocation, previousLocation);

	initializeProbeLocation(&probeLocation, actualLocation->col, actualLocation->row - 1);
	isEntirelyKilledTemp = checkForProbeLocation(gameBoard, isEntirelyKilledTemp,
		&probeLocation, actualLocation, previousLocation);

	return isEntirelyKilledTemp;
}

void initializeProbeLocation(Location* probeLocation, int col, int row) {
	probeLocation->col = col;
	probeLocation->row = row;
}

bool checkForProbeLocation(GameBoard* gameBoard, bool isEntirelyKilledTemp,
	Location* probeLocation, Location* actualLocation, Location* previousLocation) {
	if ((probeLocation->col != previousLocation->col || probeLocation->row != previousLocation->row) &&
		isThereShip(gameBoard, probeLocation))
		if (!isEntirelyKilled(gameBoard, probeLocation, actualLocation))
			isEntirelyKilledTemp = false;
	if (!isLocationKilled(gameBoard, probeLocation))
		isEntirelyKilledTemp = false;

	return isEntirelyKilledTemp;
}

bool isThereShip(GameBoard* gameBoard, Location* location) {
	int oponent = getOponent(gameBoard);
	if (location->col >= 0 &&
		location->col <= 9 &&
		location->row >= 0 &&
		location->row <= 9 &&
		gameBoard->ownBoard[oponent][location->row][location->col] == OWN_SHIP)
		return true;
	return false;
}

bool isLocationKilled(GameBoard* gameBoard, Location* probeLocation) {
	int oponent = getOponent(gameBoard);
	if (probeLocation->col >= 0 &&
		probeLocation->col <= 9 &&
		probeLocation->row >= 0 &&
		probeLocation->row <= 9 &&
		gameBoard->oponentBoard[gameBoard->activePlayer][probeLocation->row][probeLocation->col] == EMPTY &&
		gameBoard->ownBoard[oponent][probeLocation->row][probeLocation->col] == OWN_SHIP)
		return false;
	return true;
}

void killEntireShip(GameBoard* gameBoard, Location* location) {
	Location probeLocation;
	gameBoard->oponentBoard[gameBoard->activePlayer][location->row][location->col] = KILLED_SHIP;

	initializeProbeLocation(&probeLocation, location->col + 1, location->row);
	if (isNotKilledShip(gameBoard, &probeLocation))
		killEntireShip(gameBoard, &probeLocation);

	initializeProbeLocation(&probeLocation, location->col - 1, location->row);
	if (isNotKilledShip(gameBoard, &probeLocation))
		killEntireShip(gameBoard, &probeLocation);

	initializeProbeLocation(&probeLocation, location->col, location->row + 1);
	if (isNotKilledShip(gameBoard, &probeLocation))
		killEntireShip(gameBoard, &probeLocation);

	initializeProbeLocation(&probeLocation, location->col, location->row - 1);
	if (isNotKilledShip(gameBoard, &probeLocation))
		killEntireShip(gameBoard, &probeLocation);
}

bool isNotKilledShip(GameBoard* gameBoard, Location* probeLocation) {
	if (probeLocation->col >= 0 &&
		probeLocation->col <= 9 &&
		probeLocation->row >= 0 &&
		probeLocation->row <= 9 &&
		gameBoard->oponentBoard[gameBoard->activePlayer][probeLocation->row][probeLocation->col] == NOT_KILLED_SHIP)
		return true;
	return false;
}

void increasePlayersPoints(GameBoard* gameBoard) {
	gameBoard->pointsCounter[gameBoard->activePlayer]++;
}