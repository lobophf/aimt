#include "errorsHandler.h"
#include "dimensionsProduct.h"

int sub2ind2D(const int *arrayOfDimensions, const int *arrayOfSubscripts){
	inspectSubscripts(arrayOfDimensions, arrayOfSubscripts, 2);
	int subscript = arrayOfSubscripts[0] * arrayOfDimensions[1] + arrayOfSubscripts[1];
	return subscript;
}

int sub2ind(const int *arrayOfDimensions, const int *arrayOfSubscripts, const int dimensions){
	inspectSubscripts(arrayOfDimensions, arrayOfSubscripts, dimensions);
	inspectArraySize(dimensions);
	int subscriptPosition = dimensions - 1;
	int value = 0;
	value += sub2ind2D(arrayOfDimensions, arrayOfSubscripts);  
	if(subscriptPosition > 1){
		for(int i = subscriptPosition; i > 1; i--){
			int hypoDimensionsProduct = calculateDimensionsProduct(arrayOfDimensions, i);
			value += arrayOfSubscripts[i] * hypoDimensionsProduct; 
		}
	}
	return value;
}

void ind2sub2D(const int *arrayOfDimensions, const int index, int convertedIndex[]){
	inspectIndex(arrayOfDimensions, index, 2);
	convertedIndex[1] = index % arrayOfDimensions[1];
	convertedIndex[0] = index / arrayOfDimensions[1];
}

void ind2sub(const int *arrayOfDimensions, const int dimensions, const int index, int convertedIndex[]){  
	inspectIndex(arrayOfDimensions, index, dimensions);
	inspectArraySize(dimensions);
	int subscriptPosition = dimensions - 1;
	if(subscriptPosition < 2){
		ind2sub2D(arrayOfDimensions, index, convertedIndex);
	}else{
		int hypoDimensionsProduct = calculateDimensionsProduct(arrayOfDimensions, subscriptPosition);
		convertedIndex[subscriptPosition] = index / hypoDimensionsProduct;	
		int newIndex = index % hypoDimensionsProduct;
		ind2sub(arrayOfDimensions, subscriptPosition, newIndex, convertedIndex);
	}
}
