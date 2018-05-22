#ifndef SHIPSETTER_H
#define SHIPSETTER_H

#include "inputChecker.h"
#include "gameBoard.h"
#include <stdbool.h>

typedef struct ShipPosition {
	Location headLocation;
	bool isVertical;
	int length;
} ShipPosition;

void getNewShipPosition(GameBoard* gameBoard, int whichPlayer, ShipPosition* newShipPosition, int newShipLenght);

void initializeShipPosition(ShipPosition* newShipPosition, int newShipLenght);

void getNewShipPositionInput(ShipPosition* newShipPosition);

void checkTiltInput(ShipPosition* shipPosition, int tilt);

bool castTiltAsIsVertical(int tilt);

bool isShipPositionValid(char board[2][10][10], int whichPlayer, ShipPosition* shipPosition);

void setOwnShip(GameBoard* gameBoard, int whichPlayer, ShipPosition* shipPosition);

#endif 

