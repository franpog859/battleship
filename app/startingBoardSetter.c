#include "startingBoardSetter.h"
#include "gameBoard.h"
#include "inputChecker.h"
#include "shipSetter.h"
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
		for (int j = 0; j < boardSize; j++)
			for (int k = 0; k < boardSize; k++) {
				gameBoard->ownBoard[i][j][k] = EMPTY;
				gameBoard->oponentBoard[i][j][k] = EMPTY;
			}
		gameBoard->pointsCounter[i] = 0;
	}
}

void setPlayersBoard(GameBoard* gameBoard, int whichPlayer) {
	ShipPosition* newShipPosition = (ShipPosition*) malloc(sizeof(ShipPosition));
	int newShipLength = 0;
	//TODO: Add division into different sizes of ships.
	for (int shipNumber = 0; shipNumber < numberOfSingleShips; shipNumber++) {
		clearTerminal();
		printBoard(gameBoard->ownBoard, whichPlayer);

		newShipLength = countShipLength(shipNumber);
		getNewShipPosition(gameBoard, whichPlayer, newShipPosition, newShipLength);
		setOwnShip(gameBoard, whichPlayer, newShipPosition);
	}
	free(newShipPosition);
}

int countShipLength(int shipNumber) {
	if (shipNumber > 5) return 1;
	else if (shipNumber > 2) return 2;
	else if (shipNumber > 0) return 3;
	else return 4;
}