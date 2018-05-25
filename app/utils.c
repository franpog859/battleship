#include "utils.h"
#include <stdio.h>
#include <time.h>

void printHelpWithParams() {
	printf("help with params");
}

void printHelpWithShipSetting() {
	printf("help with ship setting");
}

void printHelpWithMove() {
	printf("help with move");
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
	printf("The winner is player %d!\n", winner);
	printf("You scored %d points!", points);
}

void twoSecondsSleep() {
	unsigned int second = time(0) + 2;
	while (time(0) < second);
}