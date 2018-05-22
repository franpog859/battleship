#include "startingBoardSetter.h"
#include "gameBoard.h"
#include "inputChecker.h"
#include "utils.h"
#include <stdio.h>

void setStartingGameBoard(GameBoard* gameBoard) {
	initializeGameBoard(gameBoard);
	for (int whichPlayer = 0; whichPlayer < numberOfPlayers; whichPlayer++) {
		setPlayersBoard(gameBoard, whichPlayer);

		clearTerminal();
		printBoard(gameBoard->ownBoard, whichPlayer);
		twoSecondsSleep();
	}
}

void initializeGameBoard(GameBoard* gameBoard) {
	gameBoard->activePlayer = 1; //It will be changed to 0 at the beginning of the first turn.
	gameBoard->numberOfTurns = 0;
	for (int i = 0; i < numberOfPlayers; i++) {
		for (int j = 0; j < boardSize; j++) {
			for (int k = 0; k < boardSize; k++) {
				gameBoard->ownBoard[i][j][k] = EMPTY;
				gameBoard->oponentBoard[i][j][k] = EMPTY;
			}
		}
		gameBoard->pointsCounter[i] = 0;
	}
}

void setPlayersBoard(GameBoard* gameBoard, int whichPlayer) {
	Location* newLocation = (Location*) malloc(sizeof(Location));
	//TODO: Add division into different sizes of ships.
	for (int i = 0; i < numberOfShips; i++) {
		clearTerminal();
		printBoard(gameBoard->ownBoard, whichPlayer);

		getNewShipLocation(gameBoard, whichPlayer, newLocation);
		setOwnShipLocation(gameBoard, whichPlayer, newLocation);
	}
	free(newLocation);
}

void getNewShipLocation(GameBoard* gameBoard, int whichPlayer, Location* newLocation) {
	do {
		initializeLocation(newLocation);
		getNewLocation(newLocation);
	} while (!isLocationValid(gameBoard->ownBoard, whichPlayer, newLocation));
}

void setOwnShipLocation(GameBoard* gameBoard, int whichPlayer, Location* location) {
	gameBoard->ownBoard[whichPlayer][location->row][location->col] = OWN_SHIP;
}