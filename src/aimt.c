#include "aimt.h"

long long Isub2ind(const int *arrayOfDimensions, const int *arrayOfSubscripts, const int dimensions){
	int subscriptPosition = dimensions - 1;
	long long value = 1;
	for(int i = subscriptPosition; i >= 0; i--){
		int hypoDimensionsProduct = calculateDimensionsProduct(arrayOfDimensions, i);
		value += (arrayOfSubscripts[i] - 1) * hypoDimensionsProduct; 
	}
	return value;
}

void Iind2sub(const int *arrayOfDimensions, const int dimensions, const int index, int convertedIndex[]){
	int subscriptPosition = dimensions - 1;
	if(subscriptPosition >= 0){
		int hypoDimensionsProduct = calculateDimensionsProduct(arrayOfDimensions, subscriptPosition);
		convertedIndex[subscriptPosition] = 1 + (index - 1) / hypoDimensionsProduct;
		int newIndex = 1 + (index - 1) % hypoDimensionsProduct;
		ind2sub(arrayOfDimensions, subscriptPosition, newIndex, convertedIndex);
	}
}
