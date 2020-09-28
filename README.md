# Aimt

Aimt is an array index mapping tool used to interconvert between index and subscripts. This open-source project is written in C 
language and operates by performing multidimensional conversions. As the [Matlab](https://www.mathworks.com/) and 
[Octave Forge](https://octave.sourceforge.io/), there are two functions responsible for mapping array indexes: the **sub2ind** and **ind2sub**.


<p align="center">
  <img src="https://dl.dropboxusercontent.com/s/e3m0kq4e6pru3ca/matrix.png?dl=0" alt="matrix" width="auto" height="150">
</p>


## Getting Started

In the **sub2ind** and **ind2sub** functions, the array index traverses rows, then columns, then higher dimensions. The index starts from 1, and the subscripts start from (1, ..., 1).

 > **sub2ind**

For example, let's use the **sub2ind** function to get the position index (4, 3) in a 5x4 matrix. So, we coded:

```C
int myMatrixDimensions[] = {5, 4}; 
int mySubscripts[] = {4, 3}; // index = 14
int arraySize = sizeof(myMatrixDimensions)/sizeof(myMatrixDimensions[0]);
int linearIndex = sub2ind(myMatrixDimensions, mySubscripts, arraySize);
```
