#include "gameManager.h"
#include "parameters.h"
#include "gameBoardManager.h"
#include "gameBoard.h"

void prepareAndPlay(Parameters* params) {
	GameBoard* gameBoard = malloc(sizeof(GameBoard));
	prepareGameBoard(gameBoard, params);
	
	//while (gameIsOn(gameBoard))
	//{
	//	doTheTurn(gameBoard);
	//}
	//publicWinner(gameBoard);
	free(gameBoard);
}

void prepareGameBoard(GameBoard* gameBoard, Parameters* params) {
	if (isGameLoaded(params)) {
		//loadGame(gameBoard);
	}
	else {
		setStartingGameBoard(gameBoard);
	}
}