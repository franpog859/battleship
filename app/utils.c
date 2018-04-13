#include "utils.h"
#include <stdio.h>
#include <time.h>

void printHelpWithParams() {
	printf("help with params");
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

void printWinner(int winner) {
	printf("The winner is player %d!", winner);
}

void secondSleep() {
	unsigned int second = time(0) + 1;
	while (time(0) < second);
}