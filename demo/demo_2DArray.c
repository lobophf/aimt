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

	// index to be converted.
	int index = 8;
	
	// subscripts.
	int sub[2];
	ind2sub2D(arr, index, sub);

	printf("The linear index %d was converted"
	       " to subscripts (%d, %d) of a %dx%d"
	       " array.", index, sub[0], sub[1], 
	       arr[0], arr[1]);

	return 0;
}

