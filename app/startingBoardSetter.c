#include "startingBoardSetter.h"
#include "gameBoard.h"
#include "inputChecker.h"
#include "shipSetter.h"
#include "terminal.h"
#include <stdio.h>

void setStartingGameBoard(GameBoard* gameBoard, Parameters* params) {
	initializeGameBoard(gameBoard, params);
	for (int whichPlayer = 0; whichPlayer < numberOfPlayers; whichPlayer++) {
		setPlayersBoard(gameBoard, whichPlayer);
		if (isExitParam(params))
			return;

		clearTerminal();
		printBoard(gameBoard->ownBoard, whichPlayer);
		twoSecondsSleep();
	}
}

void initializeGameBoard(GameBoard* gameBoard, Parameters* params) {
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
	gameBoard->params = params;
}

void setPlayersBoard(GameBoard* gameBoard, int whichPlayer) {
	ShipPosition newShipPosition;
	int newShipLength = 0;
	for (int shipNumber = 0; shipNumber < numberOfSingleShips; shipNumber++) {
		newShipLength = countShipLength(shipNumber);
		getNewShipPosition(gameBoard, whichPlayer, &newShipPosition, newShipLength);
		if (isExitParam(gameBoard->params))
			return;
		setOwnShip(gameBoard, whichPlayer, &newShipPosition);
	}
}

int countShipLength(int shipNumber) {
	if (shipNumber > 5) return 1;
	else if (shipNumber > 2) return 2;
	else if (shipNumber > 0) return 3;
	else return 4;
}