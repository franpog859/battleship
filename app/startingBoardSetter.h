#ifndef STARTINGBOARDSETTER_H
#define STARTINGBOARDSETTER_H

#include <stdbool.h>
#include "gameBoard.h"
#include "inputChecker.h"

void setStartingGameBoard(GameBoard* gameBoard);

void initializeGameBoard(GameBoard* gameBoard);

void setPlayersBoard(GameBoard* gameBoard, int whichPlayer);

void getNewShipLocation(GameBoard* gameBoard, int whichPlayer, Location* newLocation);

void initializeLocation(Location* location);

void setShipLocation(GameBoard* gameBoard, int whichPlayer, Location* newLocation);

#endif

