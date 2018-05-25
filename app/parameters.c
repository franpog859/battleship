#include "parameters.h"
#include <stdbool.h>
#include <stdio.h>

void getParameters(int argNumber, char ** arguments, Parameters* params) {
	const char* loadShort = "-l";
	const char* loadLong = "--load";
	const char* highScoresShort = "-s";
	const char* highScoresLong = "--scores";
	const char* helpShort = "-h";
	const char* helpLong = "--help";

	initializeParameters(params);

	for (int i = 1; i < argNumber; i++) {
		if (strcmp(arguments[i], loadShort) == 0 || 
			strcmp(arguments[i], loadLong) == 0) {
			params->load = true;
			continue;
		}
		else {
			if (strcmp(arguments[i], highScoresShort) == 0 || 
				strcmp(arguments[i], highScoresLong) == 0) {
				params->highScores = true;
				continue;
			}
			else {
				if (strcmp(arguments[i], helpShort) == 0 || 
					strcmp(arguments[i], helpLong) == 0) {
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
	params->highScores = false;
	params->help = false;
	params->exit = false;
	params->save = false;
}

bool areParametersOk(Parameters* params) {
	return !(params->help);
}

bool isHighScoresParam(Parameters* params) {
	return params->highScores;
}

bool isGameLoaded(Parameters* params) {
	return params->load;
}

bool isHelpFlag(char flag) {
	return (flag == 'h') ? true : false;
}

bool isExitFlag(char flag) {
	return (flag == 'e') ? true : false;
}

void setExitParam(Parameters* params) {
	params->exit = true;
}

bool isExitParam(Parameters* params) {
	return params->exit;
}

bool isSaveFlag(char flag) {
	return (flag == 's') ? true : false;
}

void setSaveParam(Parameters* params) {
	params->save = true;
}

bool isSaveParam(Parameters* params) {
	return params->save;
}