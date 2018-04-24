#include "parameters.h"
#include "utils.h"
#include "gameManager.h"

int main(int argNumber, char ** arguments) {
	Parameters* params = (Parameters*) malloc(sizeof(Parameters));
	getParameters(argNumber, arguments, params);
	if (areParametersOk(params)) {
		prepareAndPlay(params);
	}
	else {
		printHelpWithParams();
	}
	free(params);

	return 0;
}