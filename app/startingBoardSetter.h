#ifndef STARTINGBOARDSETTER_H
#define STARTINGBOARDSETTER_H

#include <stdbool.h>
#include "gameBoard.h"
#include "inputChecker.h"
#include "parameters.h"

void setStartingGameBoard(GameBoard* gameBoard, Parameters* params);

void initializeGameBoard(GameBoard* gameBoard, Parameters* params);

void setPlayersBoard(GameBoard* gameBoard, int whichPlayer);

int countShipLength(int shipNumber);

#endif

