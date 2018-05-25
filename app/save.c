#include "save.h"
#include "gameBoard.h"
#include "parameters.h"
#include <stdbool.h>
#include <stdio.h>


bool loadGame(GameBoard* gameBoard, Parameters* params) {
	FILE *save;
	fopen_s(&save, "../dat/save.save", "rb");
	if (save == NULL) return false;

	fread(gameBoard, sizeof(GameBoard), 1, save);
	gameBoard->params = params;

	fclose(save);
	return true;
}

void saveGame(GameBoard* gameBoard) {
	FILE *save;
	fopen_s(&save, "../dat/save.save", "wb");
	if (save == NULL) return;

	fwrite(gameBoard, sizeof(GameBoard), 1, save);
	fclose(save);
}

