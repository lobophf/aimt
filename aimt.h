#include <stdlib.h>
#include <stdio.h>

int calculateHypoDimensionsProduct(const int *arrayOfDimensions, const int indexPosition){
	int hypoDimensionsProduct = 1;
	for(int i = 0; i < indexPosition; i++){
		hypoDimensionsProduct *= arrayOfDimensions[i];
	}
	return hypoDimensionsProduct;
}

void callErrorMessage(int errorNumber){
switch(errorNumber){
		case 1:
		    printf("ERROR: The subscripts provide must be contained within a valid bound.");
		    break;
		case 2:
		    printf("ERROR: The index provide must be contained within a valid bound.");
		    break;
		case 3:
		    printf("ERROR: The size of the array must be greater or equal to 2.");
		    break;
		default:
		    printf("Unknown error");
	}
}

int isValidArraySize(const int arraySize){
	if(arraySize < 2){
		return 0; 
	}
	return 1;
}

int isValidArrayOfSubscripts(const int *arrayOfDimensions, const int *arrayOfSubscripts, const int arraySize){
	for(int i = 0; i < arraySize; i++){
		if(arrayOfSubscripts[i] < 0 || arrayOfSubscripts[i] >= arrayOfDimensions[i]){
			return 0;
		}
	}
	return 1;
}

int isValidIndex(const int *arrayOfDimensions, const int index, const int arraySize){
	int maxValue = calculateHypoDimensionsProduct(arrayOfDimensions, arraySize) - 1;
	if(index < 0 || index > maxValue){
		return 0;
	}
	return 1;
}

int sub2ind2D(const int *arrayOfDimensions, const int *arrayOfSubscripts){
	if(!isValidArrayOfSubscripts(arrayOfDimensions, arrayOfSubscripts, 2)){
		callErrorMessage(1);
		exit(EXIT_FAILURE);
	}
	int subscript = arrayOfSubscripts[0] * arrayOfDimensions[1] + arrayOfSubscripts[1];
	return subscript;
}

int sub2ind(const int *arrayOfDimensions, const int *arrayOfSubscripts, const int arraySize){
	if(!isValidArrayOfSubscripts(arrayOfDimensions, arrayOfSubscripts, arraySize)){
		callErrorMessage(1);
		exit(EXIT_FAILURE);
	}
	if(!isValidArraySize(arraySize)){
		callErrorMessage(3);
		exit(EXIT_FAILURE);
	}
	int subscript = arraySize - 1;
	int value = 0;
	value += sub2ind2D(arrayOfDimensions, arrayOfSubscripts);  
	if(subscript > 1){
		for(int i = subscript; i > 1; i--){
			int hypoDimensionsProduct = calculateHypoDimensionsProduct(arrayOfDimensions, i);
			value += arrayOfSubscripts[i] * hypoDimensionsProduct; 
		}
	}
	return value;
}

void ind2sub2D(const int *arrayOfDimensions, const int index, int convertedIndex[]){
	if(!isValidIndex(arrayOfDimensions, index, 2)){
		callErrorMessage(2);
		exit(EXIT_FAILURE);
	}
	convertedIndex[1] = index % arrayOfDimensions[1];
	convertedIndex[0] = index / arrayOfDimensions[1];
}

void ind2sub(const int *arrayOfDimensions, const int arraySize, const int index, int convertedIndex[]){  
	if(!isValidIndex(arrayOfDimensions, index, arraySize)){
		callErrorMessage(2);
		exit(EXIT_FAILURE);
	}
	if(!isValidArraySize(arraySize)){
		callErrorMessage(3);
		exit(EXIT_FAILURE);
	}
	int subscript = arraySize - 1;
	if(subscript < 2){
		ind2sub2D(arrayOfDimensions, index, convertedIndex);
	}else{
		int hypoDimensionsProduct = 1;
		hypoDimensionsProduct *= calculateHypoDimensionsProduct(arrayOfDimensions, subscript);
		convertedIndex[subscript] = index / hypoDimensionsProduct;	
		int newIndex = index % hypoDimensionsProduct;
		ind2sub(arrayOfDimensions, subscript, newIndex, convertedIndex);
	}
}
