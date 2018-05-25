#include "save.h"
#include "gameBoard.h"
#include "utils.h"
#include "parameters.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


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
}

void saveHighScore(int score) { //TODO
	FILE *scoresFile;
	Record records[MAX_RECORDS_NUMBER];
	Record newRecord;
	int numberOfRecords = 0;

	fopen_s(&scoresFile, "../dat/highScores.save", "rb");
	if (scoresFile == NULL) return false;
	for (int i = 0; !feof(scoresFile) && i < MAX_RECORDS_NUMBER; i++, numberOfRecords++) {
		fread(&records[i], sizeof(Record), 1, scoresFile);
	}
	numberOfRecords--;
	fclose(scoresFile);

	getNewRecord(&newRecord, score);
	records[numberOfRecords] = newRecord;
	qsort(records, numberOfRecords, sizeof(Record), recordCompare);

	fopen_s(&scoresFile, "../dat/highScores.save", "wb");
	if (scoresFile == NULL) return false;
	for (int i = 0; i < numberOfRecords; i++) {
		fwrite(&records[i], sizeof(Record), 1, scoresFile);
	}
	fclose(scoresFile);
}

void getNewRecord(Record *newRecord, int score) {
	newRecord->name = "asdasd";
	newRecord->score = score;
}

int recordCompare(const void * _a, const void * _b) {
	Record *a = (Record*)_a;
	Record *b = (Record*)_b;
	return (a->score - b->score);
}

void printHighScores() { //TODO
	FILE *scoresFile;
	Record buffer;
	//char buffer = '\n';
	//fopen_s(&scoresFile, "../dat/highScores.save", "rb");
	//if (scoresFile == NULL) return false;

	//while (!feof(scoresFile)) {
		//printf("%c", buffer);
		//fread(&buffer, sizeof(char), 1, scoresFile);
	//}

	fopen_s(&scoresFile, "../dat/highScores.save", "rb");
	if (scoresFile == NULL) return false;
	for (int i = 0; !feof(scoresFile) && i < MAX_RECORDS_NUMBER; i++) {
		fread(&buffer, sizeof(Record), 1, scoresFile);
		printf("%s %d", buffer.name, buffer.score);
	}

	fclose(scoresFile);
	pause();
}

