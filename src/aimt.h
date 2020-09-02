#include "errorsHandler.h"
#include "dimensionsProduct.h"

int sub2ind2D(const int *arrayOfDimensions, const int *arrayOfSubscripts);
int sub2ind(const int *arrayOfDimensions, const int *arrayOfSubscripts, const int dimensions);
void ind2sub2D(const int *arrayOfDimensions, const int index, int convertedIndex[]);
void ind2sub(const int *arrayOfDimensions, const int dimensions, const int index, int convertedIndex[]);
