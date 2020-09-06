#include "aimt2D.h"

int sub2ind2DFlip0(const int *arrayOfDimensions, const int *arrayOfSubscripts){
	inspectSubscripts(arrayOfDimensions, arrayOfSubscripts, 2);
	int subscript = arrayOfSubscripts[0] * arrayOfDimensions[1] + arrayOfSubscripts[1];
	return subscript;
}

void ind2sub2DFlip0(const int *arrayOfDimensions, const int index, int convertedIndex[]){
	inspectIndex(arrayOfDimensions, index, 2);
	convertedIndex[1] = index % arrayOfDimensions[1];
	convertedIndex[0] = index / arrayOfDimensions[1];
}
