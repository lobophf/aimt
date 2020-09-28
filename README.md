# Aimt

Aimt is an array index mapping tool used to interconvert between index and subscripts. This open-source project is written in C 
language and operates by performing multidimensional conversions. As the [Matlab](https://www.mathworks.com/) and 
[Octave Forge](https://octave.sourceforge.io/), there are two functions responsible for mapping array indexes: the **sub2ind** and **ind2sub**.


<p align="center">
  <img src="https://dl.dropboxusercontent.com/s/e3m0kq4e6pru3ca/matrix.png?dl=0" alt="matrix" width="auto" height="150">
</p>


## Getting Started

The **sub2ind** function, converts subscripts into linear indices. The array index traverses rows, then columns, then higher dimensions. 
The index starts from 1, and the subscripts start from (1, ..., 1).

For example, let's say that we have a 5x4 matrix, and we want to get the index from position (4, 3). Then, we code:

```C
int myMatrix[] = {5, 4}; 
int mySubscripts[] = {4, 3}; // index = 14
int elementsAmount = sizeof(myMatrix)/sizeof(myMatrix[0]);
int linearIndex = sub2ind(myMatrix, mySubscripts, elementsAmount);
```
