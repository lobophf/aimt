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

	int arr[] = {3, 5, 4};
	int index = 38;

	int size = sizeof(arr)/sizeof(arr[0]);

	int sub[size];
	ind2subFlip0(arr, size, index, sub);

	printf("The linear index %d was converted"
	       " to subscripts (%d, %d, %d) of a"
	       " %dx%dx%d array.\n", index, sub[0], 
	       sub[1], sub[2], arr[0], arr[1], 
	       arr[2]);
		       
	return 0;
}
