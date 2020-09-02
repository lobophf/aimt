#include "dimensionsProduct.h"

int calculateDimensionsProduct(const int *arrayOfDimensions, const int subscriptPosition){
	int dimensionsProduct = 1;
	for(int i = 0; i < subscriptPosition; i++){
		dimensionsProduct *= arrayOfDimensions[i];
	}
	return dimensionsProduct;
}
