#include "inputChecker.h"
#include "gameBoard.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>

void initializeLocation(Location* location) {
	location->col = -1; 
	location->row = -1;
}

void getNewLocation(Location* newLocation) {
	char col;
	printf("\nType a location (e.g.: C8): ");
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

bool isLocationValid(GameBoard* gameBoard, int whichPlayer, Location* newLocation) { //TODO Take care of all cases.
	if (newLocation->col > 9 || newLocation->col < 0) {
		return false;
	}
	if (newLocation->row > 9 || newLocation->row < 0) {
		return false;
	}
	if (gameBoard->ownBoard[whichPlayer][newLocation->row][newLocation->col] != EMPTY) {
		return false;
	}
	return true;
}