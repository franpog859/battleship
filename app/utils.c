#include "utils.h"
#include <stdio.h>
#include <time.h>

void printHelpWithParams() {
	printf("\nUse these flags to run the battleship CLI game:");
	printf("\n	-h	--help			- to get help with flags");
	printf("\n	-l	--load			- to to load previously saved game");
	printf("\n	-s	--highScores	- to print high scores");
	printf("\n	none				- to run the game");
}

void printHelpWithShipSetting() {
	printf("\nRemember to set proper position for your ship!");
	printf("\n	- the whole ship must fit on the board");
	printf("\n	- ships cannot overlap");
	printf("\n	- ships cannot touch each other");
	printf("\n");
	printf("\nThe first character indicates the column number for the ship prow (A - J or a - j)");
	printf("\nThe second character indicates the row number for the ship prow (0 - 9)");
	printf("\nThe third character indicates the tilt of your ship ((H or V) or (h or v))");
}

void printHelpWithMove() {
	printf("\nRemember to shot properly!");
	printf("\n	- your command must fit the board");
	printf("\n	- you cannot shot the same location more than once");
	printf("\n");
	printf("\nThe first character indicates the column number of your command (A - J or a - j)");
	printf("\nThe second character indicates the row number of your command (0 - 9)");
}

void clearTerminal() {
	system("cls");
}

void clearBuffer() {
	while (getchar() != '\n');
}

void pause() {
	printf("\nPress enter to continue...\n");
	getchar();
}

void printWinner(int winner, int points) {
	printf("\nThe winner is player %d!", winner);
	printf("\nYou scored %d points!", points);
}

void twoSecondsSleep() {
	unsigned int second = time(0) + 2;
	while (time(0) < second);
}