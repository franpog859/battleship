#ifndef SHIPSETTER_H
#define SHIPSETTER_H

#include "inputChecker.h"
#include "gameBoard.h"
#include "parameters.h"
#include <stdbool.h>

typedef struct ShipPosition {
	Location headLocation;
	bool isVertical;
	int length;
} ShipPosition;

void getNewShipPosition(GameBoard* gameBoard, int whichPlayer, ShipPosition* newShipPosition, int newShipLenght);

void initializeShipPosition(ShipPosition* newShipPosition, int newShipLenght);

void getNewShipPositionInput(ShipPosition* newShipPosition, Parameters* params);

void checkFlagsDuringPreparation(Parameters* params);

void validTiltInput(ShipPosition* shipPosition, int tilt);

bool castTiltAsIsVertical(int tilt);

bool isShipPositionValid(char board[2][10][10], int whichPlayer, ShipPosition* shipPosition);

void getTestLocation(Location* testLocation, ShipPosition* shipPosition, int lenght, int width);

bool isLocationOccupied(char board[2][10][10], int whichPlayer, Location* testLocation);

void setOwnShip(GameBoard* gameBoard, int whichPlayer, ShipPosition* shipPosition);

#endif 

