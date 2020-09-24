#include "aimt.h"

int sub2ind(const int *arrayOfDimensions, const int *arrayOfSubscripts, const int dimensions){
	inspectSubscripts(arrayOfDimensions, arrayOfSubscripts, dimensions);
	int subscriptPosition = dimensions - 1;
	int value = 1;
	for(int i = subscriptPosition; i >= 0; i--){
		int hypoDimensionsProduct = calculateDimensionsProduct(arrayOfDimensions, i);
		value += (arrayOfSubscripts[i] - 1) * hypoDimensionsProduct; 
	}
	return value;
}

void ind2sub(const int *arrayOfDimensions, const int dimensions, const int index, int convertedIndex[]){
	inspectIndex(arrayOfDimensions, index, dimensions);
	int subscriptPosition = dimensions - 1;
	if(subscriptPosition >= 0){
		int hypoDimensionsProduct = calculateDimensionsProduct(arrayOfDimensions, subscriptPosition);
		convertedIndex[subscriptPosition] = 1 + (index - 1) / hypoDimensionsProduct;
		int newIndex = 1 + (index - 1) % hypoDimensionsProduct;
		ind2sub(arrayOfDimensions, subscriptPosition, newIndex, convertedIndex);
	}
}
