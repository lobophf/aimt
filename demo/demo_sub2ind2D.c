#include <stdio.h>
#include "../aimt.h"

/* 

3x5 array filled with its indexes in 
each respective position.

 0  1  2  3  4
 5  6  7  8  9
10 11 12 13 14

*/

int main(){
	// array with 3 rows and 5 columns.
	int arr[] = {3, 5};

	// subscript to be converted.
	int sub[] = {1, 3};

	// converted subscript
	int linearIndex = sub2ind2D(arr, sub);

	printf("The subscripts (%d, %d) of a"
	       " %dx%d array was converted to"
	       " linear index %d", sub[0], 
	       sub[1], arr[0], arr[1], 
	       linearIndex);

	return 0;
}

