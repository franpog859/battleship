#ifndef SAVE_H
#define SAVE_H

#include "gameBoard.h"
#include "parameters.h"
#include <stdbool.h>

bool loadGame(GameBoard* gameBoard, Parameters* params);

void saveGame(GameBoard* gameBoard);

#endif

