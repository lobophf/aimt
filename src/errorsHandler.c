#include "errorsHandler.h"

void callErrorMessage(int errorNumber){
	switch(errorNumber){
		case 1:
		    printf("ERROR: The subscripts provide must be contained within a valid bound.");
		    break;
		case 2:
		    printf("ERROR: The index provide must be contained within a valid bound.");
		    break;
		default:
		    printf("Unknown error");
	}
}

int isValidArrayOfSubscripts(const int *arrayOfDimensions, const int *arrayOfSubscripts, const int dimensions){
	for(int i = 0; i < dimensions; i++){
		if(arrayOfSubscripts[i] < 1 || arrayOfSubscripts[i] > arrayOfDimensions[i]){
			return 0;
		}
	}
	return 1;
}

int isValidIndex(const int *arrayOfDimensions, const int index, const int dimensions){
	int maxValue = calculateDimensionsProduct(arrayOfDimensions, dimensions);
	if(index < 1 || index > maxValue){
		return 0;
	}
	return 1;
}

void inspectSubscripts(const int *arrayOfDimensions, const int *arrayOfSubscripts, const int dimensions){
	if(!isValidArrayOfSubscripts(arrayOfDimensions, arrayOfSubscripts, dimensions)){
		callErrorMessage(1);
		exit(EXIT_FAILURE);
	}
}

void inspectIndex(int const *arrayOfDimensions, int const index, int const dimension){
	if(!isValidIndex(arrayOfDimensions, index, dimension)){
		callErrorMessage(2);
		exit(EXIT_FAILURE);
	}
}
