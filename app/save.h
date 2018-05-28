#ifndef SAVE_H
#define SAVE_H

#include "gameBoard.h"
#include "parameters.h"
#include <stdbool.h>

#define RECORDS_NUMBER 20

typedef struct Record {
	char name[30];
	int score;
} Record;

bool loadGame(GameBoard* gameBoard, Parameters* params);

void saveGame(GameBoard* gameBoard);

void saveHighScore(int score);

bool readScores(Record records[]);

void addNewRecord(Record records[], int score);

int recordCompare(const void * _a, const void * _b);

void getNewRecord(Record *newRecord, int score);

int recordCompare(const void * _a, const void * _b);

bool rewriteScores(Record records[]);

void printHighScores();

#endif

