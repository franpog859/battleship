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
	checkTiltInput(newShipPosition, tilt);
	newShipPosition->isVertical = castTiltAsIsVertical(tilt);
	clearBuffer();
}

void checkTiltInput(ShipPosition* shipPosition, int tilt) {
	if (tilt == 'V' || tilt == 'v' ||
		tilt == 'H' || tilt == 'h') 
		return;
	shipPosition->headLocation.col = -1; //Col changed to inproper value. Whole position is invalid now.
}

bool castTiltAsIsVertical(int tilt) {
	return (tilt == 'V' || tilt == 'v') ? true : false;
}

bool isShipPositionValid(char board[2][10][10], int whichPlayer, ShipPosition* shipPosition) {
	return true; //TODO
}

void setOwnShip(GameBoard* gameBoard, int whichPlayer, ShipPosition* shipPosition, int shipLenght) {
	if (shipPosition->isVertical) for (int i = 0; i < shipLenght; i++) 
			gameBoard->ownBoard[whichPlayer][shipPosition->headLocation.row + i][shipPosition->headLocation.col] = OWN_SHIP;
	else for (int i = 0; i < shipLenght; i++) 
			gameBoard->ownBoard[whichPlayer][shipPosition->headLocation.row][shipPosition->headLocation.col + i] = OWN_SHIP;
}