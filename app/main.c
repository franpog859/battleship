#include "parameters.h"
#include "utils.h"

int main(int argNumber, char ** arguments) {
	Parameters* params = malloc(sizeof(Parameters));
	getParameters(argNumber, arguments, params);
	if (!areParametersOk(params)) {
		printHelp();
	}
	else {

	}
	freeParameters(params);

	return 0;
}