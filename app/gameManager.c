#include "gameManager.h"
#include "parameters.h"
#include "gameBoardManager.h"

void prepareAndPlay(Parameters* params) {
	GameBoard* gameBoard = malloc(sizeof(GameBoard));
	prepareGameBoard(gameBoard, params);
	
	//while (gameIsOn(gameBoard))
	//{
	//	doTheTurn(gameBoard);
	//}
	//publicWinner(gameBoard);
	freeGameBoard(gameBoard);
}

void prepareGameBoard(GameBoard* gameBoard, Parameters* params) {
	if (isGameLoaded(params)) {
		//loadGame(gameBoard);
	}
	else {
		setStartigGameBoard(gameBoard);
	}
}