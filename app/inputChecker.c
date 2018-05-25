#include "inputChecker.h"
#include "gameBoard.h"
#include "utils.h"
#include "parameters.h"
#include <stdbool.h>
#include <stdio.h>

void initializeLocation(Location* location) {
	location->col = -1; 
	location->row = -1;
}

void getNewLocation(Location* newLocation, Parameters* params) {
	char col;

	printf("\n	-h for help.");
	printf("\n	-e to exit.");
	printf("\n	-s to save and exit.");
	printf("\nType a location (e.g.: C8): ");
	scanf_s(" %c", &col);

	if (col == '-')
		checkFlagsDuringGame(params);
	else {
		scanf_s("%d", &newLocation->row);
		newLocation->col = castColAsInt(col);
	}
	clearBuffer();
}

void checkFlagsDuringGame(Parameters* params) {
	char flag = getchar();
	if (isHelpFlag(flag)) {
		printHelpWithMove();
		pause();
	}
	if (isExitFlag(flag))
		setExitParam(params);
	if (isSaveFlag(flag)) {
		setSaveParam(params);
		setExitParam(params);
	}
}

int castColAsInt(int col) {
	return (col < 'a') ? col - 'A' : col - 'a';
}

bool isLocationValid(char board[2][10][10], int whichPlayer, Location* newLocation) {
	if (newLocation->col > 9 || newLocation->col < 0) 
		return false;
	if (newLocation->row > 9 || newLocation->row < 0) 
		return false;
	if (board[whichPlayer][newLocation->row][newLocation->col] != EMPTY)
		return false;
	return true;
}