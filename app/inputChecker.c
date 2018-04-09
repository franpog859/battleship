#include "inputChecker.h"
#include "gameBoard.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>

void getNewLocation(Location* newLocation) {
	char col;
	printf("\nType a location (e.g.: C8) for your new ship: ");
	scanf_s(" %c", &col);
	scanf_s("%d", &newLocation->row);
	newLocation->col = castColAsInt(col);
	clearBuffer();
}

int castColAsInt(int col) {
	if (col < 'a') {
		return col - 'A';
	}
	else {
		return col - 'a';
	}
}

bool isLocationOk(GameBoard* gameBoard, int whichPlayer, Location* newLocation) { //TODO Take care of all cases.
	if (newLocation->col > 9 || newLocation->col < 0) {
		return false;
	}
	if (newLocation->row > 9 || newLocation->row < 0) {
		return false;
	}
	return true;
}