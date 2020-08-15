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
		for(int i = 0; i < subscript; i++){
			hypoDimensionsProduct *= arrayOfDimensions[i];
		}
		convertedIndex[subscript] = index / hypoDimensionsProduct;	
		int newIndex = index % hypoDimensionsProduct;
		ind2sub(arrayOfDimensions, subscript, newIndex, convertedIndex);
	}
}
