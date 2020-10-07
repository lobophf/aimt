#include "errorsHandler.h"

void callErrorMessage(int errorNumber, const char *fileName, const int codeLine){
	switch(errorNumber){
		case 1:
		    printf("Error from sub2ind function at %s:%d -- The subscripts provide must be contained within a valid bound.", fileName, codeLine);
		    break;
		case 2:
		    printf("Error from ind2sub function at %s:%d -- The index provide must be contained within a valid bound.", fileName, codeLine);
		    break;
		default:
		    printf("Unknown error");
	}
}

int isValidArrayOfSubscripts(unsigned const int *arrayOfDimensions, unsigned const int *arrayOfSubscripts, unsigned const int dimensions){
	for(int i = 0; i < dimensions; i++){
		if(arrayOfSubscripts[i] < 1 || arrayOfSubscripts[i] > arrayOfDimensions[i]){
			return 0;
		}
	}
	return 1;
}

int isValidIndex(unsigned const int *arrayOfDimensions, unsigned const int index, unsigned const int dimensions){
	unsigned int maxValue = calculateDimensionsProduct(arrayOfDimensions, dimensions);
	if(index < 1 || index > maxValue){
		return 0;
	}
	return 1;
}

void inspectSubscripts(const char *fileName, const int codeLine, unsigned const int *arrayOfDimensions, unsigned const int *arrayOfSubscripts, unsigned const int dimensions){
	if(!isValidArrayOfSubscripts(arrayOfDimensions, arrayOfSubscripts, dimensions)){
		callErrorMessage(1, fileName, codeLine);
		exit(EXIT_FAILURE);
	}
}

void inspectIndex(const char *fileName, const int codeLine, unsigned const int *arrayOfDimensions, unsigned const int index, unsigned const int dimension){
	if(!isValidIndex(arrayOfDimensions, index, dimension)){
		callErrorMessage(2, fileName, codeLine);
		exit(EXIT_FAILURE);
	}
}
