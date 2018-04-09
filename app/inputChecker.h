#ifndef INPUTCHECKER_H
#define INPUTCHECKER_H

#include <stdbool.h>
#include "gameBoard.h"

typedef struct Location {
	int col;
	int row;
} Location;

void getNewLocation(Location* newLocation);

int castColAsInt(int col);

bool isLocationOk(GameBoard* gameBoard, int whichPlayer, Location* newLocation);

#endif