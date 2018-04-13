#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <stdbool.h>

#define numberOfPlayers 2
#define boardSize 10

#define numberOfShips 20

#define EMPTY '`'
#define OWN_SHIP '#'

#define WATER '~'
#define NOT_KILLED_SHIP '#'
#define KILLED_SHIP 'X'

typedef struct GameBoard {
	char ownBoard[2][10][10]; //Two boards 10 x 10, one for each player. It's player's board.
	char oponentBoard[2][10][10]; //Two boards 10 x 10, one for each player. It's the oponent's view of the board.
	bool firstPlayerMove;
	int numberOfTurns;
	int pointsCounter[2]; //Two counters for wach player.
} GameBoard;

#endif


