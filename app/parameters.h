#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <stdbool.h>

typedef struct Parameters {
	bool load;
	bool si;
	bool help;
} Parameters;

void getParameters(int argNumber, char ** arguments, Parameters* params);

void initializeParameters(Parameters* params);

bool areParametersOk(Parameters* params);

bool isGameLoaded(Parameters* params);

bool isHelpFlag(char flag);

#endif

