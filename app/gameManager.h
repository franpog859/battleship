#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "parameters.h"
#include "gameBoard.h"
#include "inputChecker.h"
#include <stdbool.h>

void prepareAndPlay(Parameters* params);

void prepareGameBoard(GameBoard* gameBoard, Parameters* params);

bool isGameOn(GameBoard* gameBoard);

void incrementNumberOfTurns(GameBoard* gameBoard);

void publicWinner(GameBoard* gameBoard);

int getWinner(GameBoard* gameBoard);

int countPoints(GameBoard* gameBoard);

#endif 

