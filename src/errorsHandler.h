#ifndef ERRORSHANDLER_H
#define ERRORSHANDLER_H

#include <stdlib.h>
#include <stdio.h>
#include "dimensionsProduct.h"

void callErrorMessage(int errorNumber, const char *fileName, const int line);
int isValidArrayOfSubscripts(const int *arrayOfDimensions, const int *arrayOfSubscripts, const int dimensions);
int isValidIndex(const int *arrayOfDimensions, const int index, const int dimensions);
void inspectSubscripts(const char *fileName, const int codeLine, const int *arrayOfDimensions, const int *arrayOfSubscripts, const int dimensions);
void inspectIndex(const char *fileName, const int codeLine, int const *arrayOfDimensions, int const index, int const dimension);

#endif
