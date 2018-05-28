#include "save.h"
#include "gameBoard.h"
#include "utils.h"
#include "parameters.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


bool loadGame(GameBoard* gameBoard, Parameters* params) {
	FILE *save;
	fopen_s(&save, "../dat/save.save", "rb");
	if (save == NULL) return false;

	size_t itemsRead = fread(gameBoard, sizeof(GameBoard), 1, save);
	if (itemsRead * sizeof(*gameBoard) != sizeof(GameBoard)) return false;
	
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
	printf("\nSaved successfully.");
	pause();
}

void saveHighScore(int score) {
	Record records[RECORDS_NUMBER] = { 0 };

	if (!readScores(records)) return;
	addNewRecord(records, score);
	if (!rewriteScores(records)) return;

	printHighScores();
}

bool readScores(Record records[]) {
	FILE *scoresFile;
	fopen_s(&scoresFile, "../dat/highScores.save", "rb");
	if (scoresFile == NULL) return false;
	for (int i = 0; !feof(scoresFile) && i < RECORDS_NUMBER; i++) {
		fread(&records[i], sizeof(Record), 1, scoresFile);
	}
	fclose(scoresFile);
	return true;
}

void addNewRecord(Record records[], int score) {
	Record newRecord;
	getNewRecord(&newRecord, score);
	records[RECORDS_NUMBER - 1] = newRecord;
	qsort(records, RECORDS_NUMBER, sizeof(Record), recordCompare);
}

void getNewRecord(Record *newRecord, int score) {
	printf("Enter your name: ");
	fgets(newRecord->name, 30, stdin);
	if ((strlen(newRecord->name) > 0) &&
		(newRecord->name[strlen(newRecord->name) - 1] == '\n'))
		newRecord->name[strlen(newRecord->name) - 1] = '\0';

	newRecord->score = score;
}

int recordCompare(const void * _a, const void * _b) {
	Record *a = (Record*)_a;
	Record *b = (Record*)_b;
	return (a->score - b->score);
}

bool rewriteScores(Record records[]) {
	FILE *scoresFile;
	fopen_s(&scoresFile, "../dat/highScores.save", "wb");
	if (scoresFile == NULL) return false;
	for (int i = 0; i < RECORDS_NUMBER; i++) {
		fwrite(&records[i], sizeof(Record), 1, scoresFile);
	}
	fclose(scoresFile);
	return true;
}

void printHighScores() {
	FILE *scoresFile;
	Record buffer;

	fopen_s(&scoresFile, "../dat/highScores.save", "rb");
	if (scoresFile == NULL) return false;

	printf("\n    NAME			SCORE");
	for (int i = 0; !feof(scoresFile) && i < RECORDS_NUMBER; i++) {
		fread(&buffer, sizeof(Record), 1, scoresFile);
		if (buffer.score != 0)
			printf("\n%2d. %-30.25s%3d", i + 1, buffer.name, buffer.score);
	}
	fclose(scoresFile);
	pause();
}

