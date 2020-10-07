#include "aimt.h"

unsigned int Isub2ind(unsigned const int *arrayOfDimensions, unsigned const int *arrayOfSubscripts, unsigned const int dimensions){
	int subscriptPosition = dimensions - 1;
	unsigned int value = 1;
	for(int i = subscriptPosition; i >= 0; i--){
		int hypoDimensionsProduct = calculateDimensionsProduct(arrayOfDimensions, i);
		value += (arrayOfSubscripts[i] - 1) * hypoDimensionsProduct; 
	}
	return value;
}

void Iind2sub(unsigned const int *arrayOfDimensions, unsigned const int dimensions, unsigned const int index, unsigned int convertedIndex[]){
	int subscriptPosition = dimensions - 1;
	if(subscriptPosition >= 0){
		int hypoDimensionsProduct = calculateDimensionsProduct(arrayOfDimensions, subscriptPosition);
		convertedIndex[subscriptPosition] = 1 + (index - 1) / hypoDimensionsProduct;
		int newIndex = 1 + (index - 1) % hypoDimensionsProduct;
		ind2sub(arrayOfDimensions, subscriptPosition, newIndex, convertedIndex);
	}
}
