#ifndef TURN_H
#define TURN_H

#include "gameBoard.h"
#include "inputChecker.h"
#include <stdbool.h>

void doTheTurn(GameBoard* gameBoard);

void changeActivePlayer(GameBoard* gameBoard);

int getOponent(GameBoard* gameBoard);

void getMove(GameBoard* gameBoard, Location* moveLocation);

void setMove(GameBoard* gameBoard, Location* moveLocation);

void setMissingMove(GameBoard* gameBoard, Location* location);

void setKillingMove(GameBoard* gameBoard, Location* location);

bool isEntirelyKilled(GameBoard* gameBoard, Location* actualLocation, Location* previousLocation);

void initializeProbeLocation(Location* probeLocation, int col, int row);

bool checkForProbeLocation(GameBoard* gameBoard, bool isEntirelyKilledTemp,
	Location* probeLocation, Location* actualLocation, Location* previousLocation);

bool isThereShip(GameBoard* gameBoard, Location* location);

bool isLocationKilled(GameBoard* gameBoard, Location* probeLocation);

void killEntireShip(GameBoard* gameBoard, Location* location);

bool isNotKilledShip(GameBoard* gameBoard, Location* probeLocation);

void increasePlayersPoints(GameBoard* gameBoard);

#endif

