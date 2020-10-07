#ifndef ERRORSHANDLER_H
#define ERRORSHANDLER_H

#include <stdlib.h>
#include <stdio.h>
#include "dimensionsProduct.h"

void callErrorMessage(int errorNumber, const char *fileName, const int line);
int isValidArrayOfSubscripts(unsigned const int *arrayOfDimensions, unsigned const int *arrayOfSubscripts, unsigned const int dimensions);
int isValidIndex(unsigned const int *arrayOfDimensions, unsigned const int index, unsigned const int dimensions);
void inspectSubscripts(const char *fileName, const int codeLine, unsigned const int *arrayOfDimensions, unsigned const int *arrayOfSubscripts, unsigned const int dimensions);
void inspectIndex(const char *fileName, const int codeLine, unsigned const int *arrayOfDimensions, unsigned const int index, unsigned const int dimension);

#endif
