#include "dimensionsProduct.h"

unsigned int calculateDimensionsProduct(unsigned const int *arrayOfDimensions, unsigned const int subscriptPosition){
	unsigned int dimensionsProduct = 1;
	for(int i = 0; i < subscriptPosition; i++){
		dimensionsProduct *= arrayOfDimensions[i];
	}
	return dimensionsProduct;
}
