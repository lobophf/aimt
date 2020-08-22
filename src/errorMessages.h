#include <stdlib.h>
#include <stdio.h>

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
