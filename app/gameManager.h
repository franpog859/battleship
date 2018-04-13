#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "parameters.h"
#include "gameBoard.h"
#include "inputChecker.h"
#include <stdbool.h>

void prepareAndPlay(Parameters* params);

void prepareGameBoard(GameBoard* gameBoard, Parameters* params);

bool isGameOn(GameBoard* gameBoard);

void doTheTurn(GameBoard* gameBoard);

void changeActivePlayer(GameBoard* gameBoard);

int getOponent(GameBoard* gameBoard);

void getMove(GameBoard* gameBoard, Location* moveLocation);

void setMove(GameBoard* gameBoard, Location* moveLocation);

void setMissingMove(GameBoard* gameBoard, Location* location);

void setKillingMove(GameBoard* gameBoard, Location* location);

bool isEntirelyKilled(GameBoard* gameBoard, Location* location);

void increasePlayersPoints(GameBoard* gameBoard);

void publicWinner(GameBoard* gameBoard);

int getWinner(GameBoard* gameBoard);

#endif 

