#ifndef GAMEBOARDMANAGER_H
#define GAMEBOARDMANAGER_H

#include <stdbool.h>

#define numberOfPlayers 2
#define boardSize 10

#define numberOfShips 20

#define EMPTY '`'
#define SHIP '#'

typedef struct Location {
	int col;
	int row;
} Location;

typedef struct GameBoard {
	char ownBoard[2][10][10]; //Two boards 10 x 10, one for each player. It's player's board.
	char oponentBoard[2][10][10]; //Two boards 10 x 10, one for each player. It's the oponent's view of the board.
	bool firstPlayerMove;
	int numberOfTurn;
} GameBoard;

void setStartingGameBoard(GameBoard* gameBoard);

void initializeGameBoard(GameBoard* gameBoard);

void setPlayersBoard(GameBoard* gameBoard, int whichPlayer);

void printGameBoard(char board[2][10][10], int whichPlayer);

void chooseShipLocation(GameBoard* gameBoard, int whichPlayer, Location* newLocation);

void initializeLocation(Location* location);

void getNewLocation(Location* newLocation);

int castColAsInt(int col);

bool isLocationOk();

void setShipLocation(GameBoard* gameBoard, int whichPlayer, Location* newLocation);

void freeGameBoard(GameBoard* gameBoard);

#endif

