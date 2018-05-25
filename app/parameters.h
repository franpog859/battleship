#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <stdbool.h>

typedef struct Parameters {
	bool load;
	bool highScores;
	bool help;
	bool exit;
	bool save;
} Parameters;

void getParameters(int argNumber, char ** arguments, Parameters* params);

void initializeParameters(Parameters* params);

bool areParametersOk(Parameters* params);

bool isHighScoresParam(Parameters* params);

bool isGameLoaded(Parameters* params);

bool isHelpFlag(char flag);

bool isExitFlag(char flag);

void setExitParam(Parameters* params);

bool isExitParam(Parameters* params);

bool isSaveFlag(char flag);

void setSaveParam(Parameters* params);

bool isSaveParam(Parameters* params);

#endif

