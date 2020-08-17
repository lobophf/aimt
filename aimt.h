int calculateHypoDimentionProduct(const int *arrayOfDimensions, const int indexPosition){
	int hypoDimensionsProduct = 1;
	for(int i = 0; i < indexPosition; i++){
		hypoDimensionsProduct *= arrayOfDimensions[i];
	}
	return hypoDimensionsProduct;
}

int sub2ind2D(const int *arrayOfDimensions, const int *arrayOfSubscripts){
	return arrayOfSubscripts[0] * arrayOfDimensions[1] + arrayOfSubscripts[1];	
}

int sub2ind(const int *arrayOfDimensions, const int *arrayOfSubscripts, const int arraySize){
	int subscript = arraySize - 1;
	int value = 0;
	value += sub2ind2D(arrayOfDimensions, arrayOfSubscripts);  
	if(subscript > 1){
		for(int i = subscript; i > 1; i--){
			int hypoDimensionsProduct = calculateHypoDimentionProduct(arrayOfDimensions, i);
			value += arrayOfSubscripts[i] * hypoDimensionsProduct; 
		}
	}
	return value;
}

void ind2sub2D(const int *arrayOfDimensions, const int index, int convertedIndex[]){
	convertedIndex[1] = index % arrayOfDimensions[1];
	convertedIndex[0] = index / arrayOfDimensions[1];
}

void ind2sub(const int *arrayOfDimensions, const int arraySize, const int index, int convertedIndex[]){  
	int subscript = arraySize - 1;
	if(subscript < 2){
		ind2sub2D(arrayOfDimensions, index, convertedIndex);
	}else{
		int hypoDimensionsProduct = 1;
		hypoDimensionsProduct *= calculateHypoDimentionProduct(arrayOfDimensions, subscript);
		convertedIndex[subscript] = index / hypoDimensionsProduct;	
		int newIndex = index % hypoDimensionsProduct;
		ind2sub(arrayOfDimensions, subscript, newIndex, convertedIndex);
	}
}
