#ifndef SAVE_H
#define SAVE_H

#include "gameBoard.h"
#include "parameters.h"
#include <stdbool.h>

#define MAX_RECORDS_NUMBER 50

typedef struct Record {
	char *name;
	int score;
} Record;

bool loadGame(GameBoard* gameBoard, Parameters* params);

void saveGame(GameBoard* gameBoard);

void saveHighScore(int score);

void getNewRecord(Record *newRecord, int score);

int recordCompare(const void * _a, const void * _b);

void printHighScores();

#endif

