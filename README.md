# Aimt

Aimt is an array index mapping tool used to interconvert between index and subscripts. This open-source project is written in [C 
language](https://en.wikipedia.org/wiki/C_(programming_language)) and operates by performing multidimensional conversions. As the [Matlab](https://www.mathworks.com/) and 
[Octave Forge](https://octave.sourceforge.io/), there are two functions to mapping array indexes: the **sub2ind** and **ind2sub**.


<p align="center">
  <img src="https://dl.dropboxusercontent.com/s/e3m0kq4e6pru3ca/matrix.png?dl=0" alt="matrix" width="auto" height="150">
</p>


## Getting Started

In the **sub2ind** and **ind2sub** functions, the array index traverses rows, then columns, then higher dimensions. The index starts from 1, and the subscripts start from (1, ..., 1).

 > **sub2ind**

For example, let's use the **sub2ind** function to get a linear index form of a (4, 3) subscripts in a 5x4 matrix. So, we code:

```C
int myMatrixDimensions[] = {5, 4}; 
int mySubscripts[] = {4, 3}; // index = 14
int arraySize = sizeof(myMatrixDimensions)/sizeof(myMatrixDimensions[0]);
int linearIndex = sub2ind(myMatrixDimensions, mySubscripts, arraySize);
```

 > **ind2sub**

On the other hand, we can use **ind2sub** function to move in the opposite way. For example, in a 5x4 matrix, one linear index is 14, and we can get these subscripts form coding like this:

```C
int myMatrixDimensions[] = {5, 4}; 
int myIndex = 14; // subscripts = (4, 3)
int arraySize = sizeof(myMatrixDimensions)/sizeof(myMatrixDimensions[0]);
int mySubscripts[arraySize];
ind2sub(myMatrixDimensions, arraySize, myIndex, mySubscripts);
```
See the [demos folder](https://github.com/lobophf/aimt/tree/master/demo) for complete examples.

## Installation
Just copy the [src folder](https://github.com/lobophf/aimt/tree/master/src) into your project and add the [include](https://gcc.gnu.org/onlinedocs/cpp/Include-Syntax.html) directive.

``` C
#include "../src/aimt.h"

int main (int argc, char *argv[]){
  // stuffs to do...
  return 0;
}
```

## Contributing

I'm so glad when I see improvements done by other people. Feel free to contribute by opening pull requests with improvements, fixing bugs or typing mistakes, or even open an issue to report errors. See some useful stuffs in [CONTRIBUTION.md](https://github.com/lobophf/aimt/blob/documentation/CONTRIBUTION.md

## License

Aimt is a MIT licensed, as found in the [LICENSE](https://github.com/lobophf/aimt/blob/master/LICENSE) file.


