#include <stdio.h>
#include "../aimt.h"

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
