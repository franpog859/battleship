#include "shipSetter.h"
#include "inputChecker.h"
#include "parameters.h"
#include "terminal.h"
#include <stdio.h>
#include <stdbool.h>

void getNewShipPosition(GameBoard* gameBoard, int whichPlayer, ShipPosition* newShipPosition, int newShipLenght) {
	do {
		clearTerminal();
		printBoard(gameBoard->ownBoard, whichPlayer);

		initializeShipPosition(newShipPosition, newShipLenght);
		getNewShipPositionInput(newShipPosition, gameBoard->params); 
	} while (!isShipPositionValid(gameBoard->ownBoard, whichPlayer, newShipPosition) && !isExitParam(gameBoard->params));
}

void initializeShipPosition(ShipPosition* shipPosition, int newShipLenght) {
	shipPosition->headLocation.col = -1;
	shipPosition->headLocation.row = -1;
	shipPosition->isVertical = true;
	shipPosition->length = newShipLenght;
}

void getNewShipPositionInput(ShipPosition* newShipPosition, Parameters* params) {
	char col, tilt;

	printf("\n	-h	- to get help with ship setting");
	printf("\n	-e	- to exit the game");
	printf("\ne.g.: C8H		- for ship rotated horizontally with prow at C8  (C8V	- ...vertically...)");
	printf("\nType a location for ship of %d size: ", newShipPosition->length);
	scanf_s(" %c", &col);

	if (col == '-')
		checkFlagsDuringPreparation(params);
	else {
		newShipPosition->headLocation.col = castColAsInt(col);
		scanf_s("%d", &newShipPosition->headLocation.row);
		scanf_s(" %c", &tilt);
		validTiltInput(newShipPosition, tilt);
		newShipPosition->isVertical = castTiltAsIsVertical(tilt);
	}

	clearBuffer();
}

void checkFlagsDuringPreparation(Parameters* params) {
	char flag = getchar();
	if (isHelpFlag(flag)) {
		printHelpWithShipSetting();
		pause();
	}
	if (isExitFlag(flag))
		setExitParam(params);
}

void validTiltInput(ShipPosition* shipPosition, int tilt) {
	if (tilt == 'V' || tilt == 'v' ||
		tilt == 'H' || tilt == 'h') 
		return;
	shipPosition->headLocation.col = -1; //Col is changed to inproper value. Whole position is invalid now.
}

bool castTiltAsIsVertical(int tilt) {
	return (tilt == 'V' || tilt == 'v') ? true : false;
}

bool isShipPositionValid(char board[2][10][10], int whichPlayer, ShipPosition* shipPosition) {
	Location testLocation;
	initializeLocation(&testLocation);

	for (int length = 0; length < shipPosition->length; length++) {
		getTestLocation(&testLocation, shipPosition, length, 0);
		if (!isLocationValid(board, whichPlayer, &testLocation)) return false;
	}
	for (int length = -1; length < shipPosition->length + 1; length++) 
		for (int width = -1; width < 2; width++) {
			getTestLocation(&testLocation, shipPosition, length, width);
			if (isLocationOccupied(board, whichPlayer, &testLocation)) return false;
		}	
	return true; 
}

void getTestLocation(Location* testLocation, ShipPosition* shipPosition, int lenght, int width) {
	testLocation->col = shipPosition->headLocation.col + ((shipPosition->isVertical) ? width : lenght);
	testLocation->row = shipPosition->headLocation.row + ((shipPosition->isVertical) ? lenght : width);
}

bool isLocationOccupied(char board[2][10][10], int whichPlayer, Location* testLocation) {
	if (!(testLocation->col > 9 || testLocation->col < 0 ||
		testLocation->row > 9 || testLocation->row < 0) &&
		board[whichPlayer][testLocation->row][testLocation->col] != EMPTY)
		return true;
	return false;
}

void setOwnShip(GameBoard* gameBoard, int whichPlayer, ShipPosition* shipPosition) {
	if (shipPosition->isVertical) 
		for (int i = 0; i < shipPosition->length; i++) 
			gameBoard->ownBoard[whichPlayer][shipPosition->headLocation.row + i][shipPosition->headLocation.col] = OWN_SHIP;
	else 
		for (int i = 0; i < shipPosition->length; i++)
			gameBoard->ownBoard[whichPlayer][shipPosition->headLocation.row][shipPosition->headLocation.col + i] = OWN_SHIP;
}