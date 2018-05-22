#ifndef STARTINGBOARDSETTER_H
#define STARTINGBOARDSETTER_H

#include <stdbool.h>
#include "gameBoard.h"
#include "inputChecker.h"

void setStartingGameBoard(GameBoard* gameBoard);

void initializeGameBoard(GameBoard* gameBoard);

void setPlayersBoard(GameBoard* gameBoard, int whichPlayer);

int countShipLength(int shipNumber);

#endif

