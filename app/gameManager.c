#include "gameManager.h"
#include "parameters.h"
#include "gameBoard.h"
#include "utils.h"
#include "save.h"
#include "inputChecker.h"
#include <stdbool.h>

void prepareAndPlay(Parameters* params) {
	GameBoard gameBoard;
	prepareGameBoard(&gameBoard, params);
	
	while (isGameOn(&gameBoard) && !isExitParam(params)) {
		incrementNumberOfTurns(&gameBoard);
		doTheTurn(&gameBoard);
	}

	if (!isExitParam(params)) {
		publicWinner(&gameBoard);
		//TODO: saveHighScore(&gameBoard);
	}
	else if (isSaveParam(params))
		saveGame(&gameBoard);
}

void prepareGameBoard(GameBoard* gameBoard, Parameters* params) {
	if (isGameLoaded(params))
		loadGame(gameBoard, params);
	else 
		setStartingGameBoard(gameBoard, params);
}

bool isGameOn(GameBoard* gameBoard) {
	int lastTurnPlayer = gameBoard->activePlayer;
	if (gameBoard->pointsCounter[lastTurnPlayer] == numberOfShips) 
		return false;
	return true;
}

void incrementNumberOfTurns(GameBoard* gameBoard) {
	if (gameBoard->activePlayer == 1) 
		gameBoard->numberOfTurns++;
}

void publicWinner(GameBoard* gameBoard) {
	int winner = getWinner(gameBoard);
	int points = countPoints(gameBoard);
	clearTerminal();
	printWinner(winner, points);
	pause();
}

int getWinner(GameBoard* gameBoard) { 
	int lastTurnPlayer = gameBoard->activePlayer;
	return lastTurnPlayer;
}

int countPoints(GameBoard* gameBoard) {
	const int MAX_NUMBER_OF_TURNS = boardSize * boardSize;
	const int MIN_NUMBER_OF_TURNS = numberOfShips;
	
	return MAX_NUMBER_OF_TURNS + MIN_NUMBER_OF_TURNS - gameBoard->numberOfTurns;
}
