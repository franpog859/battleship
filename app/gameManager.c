#include "gameManager.h"
#include "parameters.h"
#include "gameBoardManager.h"

void prepareAndPlay(Parameters* params) {
	GameBoard* gameBoard = malloc(sizeof(GameBoard));
	if (isGameLoaded(params)) {
		loadGame(gameBoard);
	}
	else {
		setPlayersGameBoards(gameBoard);
	}
	freeGameBoard(gameBoard);
}