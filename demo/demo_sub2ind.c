#include <stdio.h>
#include "../src/aimt.h"

/* 

3x5x4 array sections filled with its 
indexes in each respective position.

dim3 = 0
 0  1  2  3  4
 5  6  7  8  9
10 11 12 13 14

dim3 = 1
15 16 17 18 19
20 21 22 23 24
25 26 27 28 29

dim3 = 2
30 31 32 33 34
35 36 37 38 39
40 41 42 43 44

dim3 = 3
45 46 47 48 49
50 51 52 53 54
55 56 57 58 59

*/

int main(){
	// array with 3 rows and 5 columns.
	int arr[] = {3, 5, 4};

	// subscript to be converted.
	int sub[] = {1, 3, 2};
	
	// size of arr.
	int arrSize = sizeof(arr)/sizeof(arr[0]);

	// converted subscript
	int linearIndex = sub2indFlip0(arr, sub, arrSize);

	printf("The subscripts (%d, %d, %d) of a"
	       " %dx%dx%d array was converted to"
	       " linear index %d.\n", sub[0], sub[1], 
	       sub[2], arr[0], arr[1], arr[2], 
	       linearIndex);

	return 0;
}

