#include "shipSetter.h"
#include "inputChecker.h"
#include <stdio.h>
#include <stdbool.h>

void getNewShipPosition(GameBoard* gameBoard, int whichPlayer, ShipPosition* newShipPosition, int newShipLenght) {
	do {
		initializeShipPosition(newShipPosition, newShipLenght);
		getNewShipPositionInput(newShipPosition); 
	} while (!isShipPositionValid(gameBoard->ownBoard, whichPlayer, newShipPosition));
}

void initializeShipPosition(ShipPosition* shipPosition, int newShipLenght) {
	shipPosition->headLocation.col = -1;
	shipPosition->headLocation.row = -1;
	shipPosition->isVertical = true;
	shipPosition->length = newShipLenght;
}

void getNewShipPositionInput(ShipPosition* newShipPosition) {
	char col;
	char tilt;

	printf("\ne.g.: C8H		- for ship rotated horizontally with prow at C8  (C8V	- ...vertically...)");
	printf("\nType a location for ship of %d size: ", newShipPosition->length);

	scanf_s(" %c", &col);
	newShipPosition->headLocation.col = castColAsInt(col);
	scanf_s("%d", &newShipPosition->headLocation.row);
	scanf_s(" %c", &tilt);
	validTiltInput(newShipPosition, tilt);
	newShipPosition->isVertical = castTiltAsIsVertical(tilt);

	clearBuffer();
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

	if (shipPosition->isVertical) {
		for (int i = 0; i < shipPosition->length; i++) {
			testLocation.col = shipPosition->headLocation.col;
			testLocation.row = shipPosition->headLocation.row + i;
			if (!isLocationValid(board, whichPlayer, &testLocation)) return false;
		}
		for (int i = -1; i < shipPosition->length + 1; i++) for (int j = -1; j < 2; j++) {
			testLocation.col = shipPosition->headLocation.col + j;
			testLocation.row = shipPosition->headLocation.row + i;
			if (isLocationOccupied(board, whichPlayer, testLocation)) return false;
		}
	}
	else {
		for (int i = 0; i < shipPosition->length; i++) {
			testLocation.col = shipPosition->headLocation.col + i;
			testLocation.row = shipPosition->headLocation.row;
			if (!isLocationValid(board, whichPlayer, &testLocation)) return false;
		}
		for (int i = -1; i < shipPosition->length + 1; i++) for (int j = -1; j < 2; j++) {
			testLocation.col = shipPosition->headLocation.col + i;
			testLocation.row = shipPosition->headLocation.row + j;
			if (isLocationOccupied(board, whichPlayer, testLocation)) return false;
		}
	}
	return true; 
}

bool isLocationOccupied(char board[2][10][10], int whichPlayer, const Location testLocation) {
	if (!(testLocation.col > 9 || testLocation.col < 0 ||
		testLocation.row > 9 || testLocation.row < 0) &&
		board[whichPlayer][testLocation.row][testLocation.col] != EMPTY)
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