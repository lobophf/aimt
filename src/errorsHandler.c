#include "errorsHandler.h"

void callErrorMessage(int errorNumber){
	switch(errorNumber){
		case 1:
		    printf("ERROR: The subscripts provide must be contained within a valid bound.");
		    break;
		case 2:
		    printf("ERROR: The index provide must be contained within a valid bound.");
		    break;
		case 3:
		    printf("ERROR: The size of the array must be greater or equal to 2.");
		    break;
		default:
		    printf("Unknown error");
	}
}

int isValidArraySize(const int dimensions){
	if(dimensions < 2){
		return 0; 
	}
	return 1;
}

int isValidArrayOfSubscripts(const int *arrayOfDimensions, const int *arrayOfSubscripts, const int dimensions){
	for(int i = 0; i < dimensions; i++){
		if(arrayOfSubscripts[i] < 0 || arrayOfSubscripts[i] >= arrayOfDimensions[i]){
			return 0;
		}
	}
	return 1;
}

int isValidIndex(const int *arrayOfDimensions, const int index, const int dimensions){
	int maxValue = calculateDimensionsProduct(arrayOfDimensions, dimensions) - 1;
	if(index < 0 || index > maxValue){
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

void inspectArraySize(int const dimensions){
	if(!isValidArraySize(dimensions)){
		callErrorMessage(3);
		exit(EXIT_FAILURE);
	}
}
