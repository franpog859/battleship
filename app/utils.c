#include "utils.h"
#include <stdio.h>

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