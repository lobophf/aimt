#include <stdio.h>
#include "../src/aimt.h"

/* 

3x5x4 array sections filled with its 
indexes in each respective position.

dim3 = 1
 1  4  7 10 13
 2  5  8 11 14
 3  6  9 12 15

dim3 = 2
16 19 22 25 28
17 20 23 26 29
18 21 24 27 30

dim3 = 3
31 34 37 40 43
32 35 38 41 44
33 36 39 42 45

dim3 = 4
46 49 52 55 58
47 50 53 56 59
48 51 54 57 60

*/

int main(){

	unsigned int arr[] = {3, 5, 4};
	unsigned index = 47;

	unsigned int size = sizeof(arr)/sizeof(arr[0]);

	unsigned sub[size];
	ind2sub(arr, size, index, sub);

	printf("The linear index %u was converted"
	       " to subscripts (%u, %u, %u) of a"
	       " %ux%ux%u array.\n", index, sub[0], 
	       sub[1], sub[2], arr[0], arr[1], 
	       arr[2]);
		       
	return 0;
}
