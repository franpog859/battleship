#include "parameters.h"
#include "utils.h"
#include "gameManager.h"

int main(int argNumber, char ** arguments) {
	Parameters* params = malloc(sizeof(Parameters));
	getParameters(argNumber, arguments, params);
	if (areParametersOk(params)) {
		prepareAndPlay(params);
	}
	else {
		printHelpWithParams();
	}
	freeParameters(params);

	return 0;
}