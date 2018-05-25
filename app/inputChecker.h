#ifndef INPUTCHECKER_H
#define INPUTCHECKER_H

#include <stdbool.h>
#include "gameBoard.h"
#include "parameters.h"

typedef struct Location {
	int col;
	int row;
} Location;

void initializeLocation(Location* location);

void getNewLocation(Location* newLocation, Parameters* params);

void checkFlagsDuringGame(Parameters* params);

int castColAsInt(int col);

bool isLocationValid(char board[2][10][10], int whichPlayer, Location* newLocation);

#endif