#include "aimt.h"

int sub2indFlip0(const int *arrayOfDimensions, const int *arrayOfSubscripts, const int dimensions){
	inspectSubscripts(arrayOfDimensions, arrayOfSubscripts, dimensions);
	inspectArraySize(dimensions);
	int subscriptPosition = dimensions - 1;
	int value = 0;
	value += sub2ind2DFlip0(arrayOfDimensions, arrayOfSubscripts);  
	if(subscriptPosition > 1){
		for(int i = subscriptPosition; i > 1; i--){
			int hypoDimensionsProduct = calculateDimensionsProduct(arrayOfDimensions, i);
			value += arrayOfSubscripts[i] * hypoDimensionsProduct; 
		}
	}
	return value;
}

void ind2subFlip0(const int *arrayOfDimensions, const int dimensions, const int index, int convertedIndex[]){  
	inspectIndex(arrayOfDimensions, index, dimensions);
	inspectArraySize(dimensions);
	int subscriptPosition = dimensions - 1;
	if(subscriptPosition < 2){
		ind2sub2DFlip0(arrayOfDimensions, index, convertedIndex);
	}else{
		int hypoDimensionsProduct = calculateDimensionsProduct(arrayOfDimensions, subscriptPosition);
		convertedIndex[subscriptPosition] = index / hypoDimensionsProduct;	
		int newIndex = index % hypoDimensionsProduct;
		ind2subFlip0(arrayOfDimensions, subscriptPosition, newIndex, convertedIndex);
	}
}
