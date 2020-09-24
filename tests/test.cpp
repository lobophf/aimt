#include <iostream>
#include <gtest/gtest.h>
#include "../src/aimt.h"

TEST(ind2sub, basicTest){
	int index = 38;
	int arr[] = {3, 5, 4};
	int size = sizeof(arr)/sizeof(arr[0]);

	int sub[size];
	ind2sub(arr, size, index, sub);
	int realSub[] = {2, 3, 3};	

	for(int i = 0; i < size; i++){
		ASSERT_EQ(realSub[i], sub[i]);
	}
}

TEST(sub2ind, basicTest){
	int arr[] = {3, 5, 4};
	int sub[] = {2, 3, 3};
	int arrSize = sizeof(arr)/sizeof(arr[0]);

	int linearIndex = sub2ind(arr, sub, arrSize);
	EXPECT_EQ(linearIndex, 38);
}

int main(int argc, char **argv){
	
	testing::InitGoogleTest(&argc, argv);	
	return RUN_ALL_TESTS();
}
