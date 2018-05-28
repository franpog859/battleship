#include "parameters.h"
#include "terminal.h"
#include "save.h"
#include "game.h"

#include <stdlib.h> 
#include <crtdbg.h> 
#define _CRTDBG_MAP_ALLOC 

int main(int argNumber, char ** arguments) {
	Parameters params;
	getParameters(argNumber, arguments, &params);

	if (areParametersOk(&params)) {
		if (isHighScoresParam(&params))
			printHighScores();
		else
			prepareAndPlay(&params);
	}
	else
		printHelpWithParams();
	
	_CrtDumpMemoryLeaks();
	return 0;
}