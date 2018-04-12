#include "startingBoardSetter.h"
#include "gameBoard.h"
#include "inputChecker.h"
#include "gameBoardManager.h"
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