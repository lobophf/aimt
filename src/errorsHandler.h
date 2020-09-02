#include <stdlib.h>
#include <stdio.h>
#include "dimensionsProduct.h"

#ifndef ERRORSHANDLER_H
#define ERRORSHANDLER_H

void callErrorMessage(int errorNumber);
int isValidArraySize(const int dimensions);
int isValidArrayOfSubscripts(const int *arrayOfDimensions, const int *arrayOfSubscripts, const int dimensions);
int isValidIndex(const int *arrayOfDimensions, const int index, const int dimensions);
void inspectSubscripts(const int *arrayOfDimensions, const int *arrayOfSubscripts, const int dimensions);
void inspectIndex(int const *arrayOfDimensions, int const index, int const dimension);
void inspectArraySize(int const dimensions);

#endif
