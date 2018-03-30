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

void freeParameters(Parameters* params);

#endif // !PARAMETERS_H
