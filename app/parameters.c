#include "parameters.h"
#include <stdbool.h>

void getParameters(int argNumber, char ** arguments, Parameters* params) {
	const char* loadShort = "-l";
	const char* loadLong = "--load";
	const char* siShort = "-s";
	const char* siLong = "--si";
	const char* helpShort = "-h";
	const char* helpLong = "--help";

	initializeParameters(params);

	for (int i = 1; i < argNumber; i++) {
		if (strcmp(arguments[i], loadShort) == 0 || strcmp(arguments[i], loadLong) == 0) {
			params->load = true;
			continue;
		}
		else {
			if (strcmp(arguments[i], siShort) == 0 || strcmp(arguments[i], siLong) == 0) {
				params->si = true;
				continue;
			}
			else {
				if (strcmp(arguments[i], helpShort) == 0 || strcmp(arguments[i], helpLong) == 0) {
					params->help = true;
					continue;
				}
			}
		}
		params->help = true;
		return;
	}
}

void initializeParameters(Parameters* params) {
	params->load = false;
	params->si = false;
	params->help = false;
}

bool areParametersOk(Parameters* params) {
	return !(params->help);
}

bool isGameLoaded(Parameters* params) {
	return params->load;
}

void freeParameters(Parameters* params) {
	free(params);
}