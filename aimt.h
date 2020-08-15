void ind2sub2D(const int *arrayOfDimensions, const int index, int convertedIndex[]){
	convertedIndex[1] = index % arrayOfDimensions[1];
	convertedIndex[0] = index / arrayOfDimensions[1];
}
