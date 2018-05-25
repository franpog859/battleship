#include "parameters.h"
#include "utils.h"
#include "gameManager.h"

int main(int argNumber, char ** arguments) {
	Parameters params;
	getParameters(argNumber, arguments, &params);

	if (areParametersOk(&params)) {
		if (isHighScoresParam(&params))
			;//TODO printHighScores();
		else
			prepareAndPlay(&params);
	}
	else
		printHelpWithParams();
	return 0;
}