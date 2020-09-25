#include <iostream>
#include <gtest/gtest.h>
#include "../src/aimt.h"

TEST(sub2indTest, convertTest) {

	int arr1[] = {3, 5, 4};
	int sub10[] = {2, 1, 4}; 
	EXPECT_EQ(47, sub2ind(arr1, sub10, 3));
	int sub11[] = {2, 4, 4}; 
	EXPECT_EQ(56, sub2ind(arr1, sub11, 3));
	int sub12[] = {1, 1, 1}; 
	EXPECT_EQ(1, sub2ind(arr1, sub12, 3));
	int sub13[] = {3, 5, 4}; 
	EXPECT_EQ(60, sub2ind(arr1, sub13, 3));

	int arr2[] = {3, 5, 4, 3, 1, 4, 2};
	int sub20[] = {3, 4, 2, 3, 1, 4, 2}; 
	EXPECT_EQ(1407, sub2ind(arr2, sub20, 7));
	int sub21[] = {1, 4, 3, 2, 1, 4, 1}; 
	EXPECT_EQ(640, sub2ind(arr2, sub21, 7));
	int sub22[] = {3, 1, 3, 1, 1, 2, 1}; 
	EXPECT_EQ(213, sub2ind(arr2, sub22, 7));
	int sub23[] = {3, 5, 4, 3, 1, 4, 2}; 
	EXPECT_EQ(1440, sub2ind(arr2, sub23, 7));
	int sub24[] = {1, 1, 1, 1, 1, 1, 1}; 
	EXPECT_EQ(1, sub2ind(arr2, sub24, 7));

	int arr3[] = {10};
	int sub30[] = {1}; 
	EXPECT_EQ(1, sub2ind(arr3, sub30, 1));
	int sub31[] = {10}; 
	EXPECT_EQ(10, sub2ind(arr3, sub31, 1));
	int sub32[] = {5}; 
	EXPECT_EQ(5, sub2ind(arr3, sub32, 1));
	int sub33[] = {8}; 
	EXPECT_EQ(8, sub2ind(arr3, sub33, 1));
}

TEST(ind2subTest, convertTest) {

	int size = 3;
	int arr1[] = {3, 5, 4};
	int sub10[] = {2, 1, 4};
	int convSub10[size];
	ind2sub(arr1, size, 47, convSub10);
	for(int i = 0; i < size; i++) EXPECT_EQ(sub10[i], convSub10[i]);
	
	int sub11[] = {3, 3, 3};
	int convSub11[size];
	ind2sub(arr1, size, 39, convSub11);
	for(int i = 0; i < size; i++) EXPECT_EQ(sub11[i], convSub11[i]);
	
	int sub12[] = {1, 4, 1};
	int convSub12[size];
	ind2sub(arr1, size, 10, convSub12);
	for(int i = 0; i < size; i++) EXPECT_EQ(sub12[i], convSub12[i]);
	
	int sub13[] = {3, 5, 4};
	int convSub13[size];
	ind2sub(arr1, size, 60, convSub13);
	for(int i = 0; i < size; i++) EXPECT_EQ(sub13[i], convSub13[i]);
	
	int sub14[] = {1, 1, 1};
	int convSub14[size];
	ind2sub(arr1, size, 1, convSub14);
	for(int i = 0; i < size; i++) EXPECT_EQ(sub14[i], convSub14[i]);



	size = 8;
	int arr2[] = {6, 3, 7, 5, 4, 1, 2, 8};
	int sub20[] = {6, 1, 6, 5, 4, 1, 2, 8};
	int convSub20[size];
	ind2sub(arr2, size, 40290, convSub20);
	for(int i = 0; i < size; i++) EXPECT_EQ(sub20[i], convSub20[i]);
	
	int sub21[] = {4, 1, 1, 3, 2, 1, 2, 8};
	int convSub21[size];
	ind2sub(arr2, size, 38686, convSub21);
	for(int i = 0; i < size; i++) EXPECT_EQ(sub21[i], convSub21[i]);
	
	int sub22[] = {4, 1, 4, 4, 1, 1, 2, 2};
	int convSub22[size];
	ind2sub(arr2, size, 7996, convSub22);
	for(int i = 0; i < size; i++) EXPECT_EQ(sub22[i], convSub22[i]);
	
	int sub23[] = {1, 1, 1, 1, 1, 1, 1, 1};
	int convSub23[size];
	ind2sub(arr2, size, 1, convSub23);
	for(int i = 0; i < size; i++) EXPECT_EQ(sub23[i], convSub23[i]);
	
	int sub24[] = {6, 3, 7, 5, 4, 1, 2, 8};
	int convSub24[size];
	ind2sub(arr2, size, 40320, convSub24);
	for(int i = 0; i < size; i++) EXPECT_EQ(sub24[i], convSub24[i]);
}

int main(int argc, char **argv){
	
	testing::InitGoogleTest(&argc, argv);	
	return RUN_ALL_TESTS();
}
