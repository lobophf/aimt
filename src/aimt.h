#ifndef AIMT_H
#define AIMT_H

#include "errorsHandler.h"
#include "dimensionsProduct.h"

/**
 *
 * @brief Converts subscripts into linear indices. The linear index traverses rows, 
 * then columns, then higher dimensions. The index starts from 1, and the subscripts start 
 * from (1, ..., 1).
 *
 * @param[in] arrayOfDimensions where each element represents the is the size of the array 
 * in the respective dimension.
 *
 * @param[in] arrayOfSubscripts in which the set of its elements form the position to be 
 * converted.
 * @param[in] dimensions is size of the @paramname{arrayOfDimensions} and 
 * @paramname{arrayOfSubscripts}.
 * @return a converted linear index.
 *
 * @warning Ensure that @paramname{arrayOfDimensions} and @paramname{arrayOfSubscripts} 
 * share the same @paramname{dimension}, in order to get a proper result.
 */

#define sub2ind(arrayOfDimensions, arrayOfSubscripts, dimensions) ({ \
	inspectSubscripts(__FILE__, __LINE__, arrayOfDimensions, arrayOfSubscripts, dimensions); \
	Isub2ind(arrayOfDimensions, arrayOfSubscripts, dimensions); \
})

/** 
 *
 * @example demo_sub2ind.c
 * This is an example of how to use the sub2ind function.
 */

/**
 *
 * @brief Converts linear index into subscripts. The linear index traverses rows, 
 * then columns, then higher dimensions. The index starts from 1, and the subscripts start 
 * from (1, ..., 1).
 *
 * @param[in] arrayOfDimensions where each element represents the is the size of the array 
 * in the respective dimension.
 * @param[in] dimensions is size of the @paramname{arrayOfDimensions} and 
 * @paramname{convertedIndex}.
 * @param[in] index to be converted.
 * @param[in, out] convertedIndex give the converted subscripts set.
 * 
 * @pre The @paramname{index} must fit in the @paramname{arrayOfDimensions}.
 * 
 * @warning Ensure that @paramname{arrayOfDimensions} and @paramname{arrayOfSubscripts} 
 * share the same @paramname{dimension}, in order to get a proper result.
 */

#define ind2sub(arrayOfDimensions, dimensions, index, convertedIndex) ({ \
	inspectIndex(__FILE__, __LINE__, arrayOfDimensions, index, dimensions); \
	Iind2sub(arrayOfDimensions, dimensions, index, convertedIndex); \
})

/** 
 *
 * @example demo_ind2sub.c
 * This is an example of how to use the ind2sub function.
 */

unsigned int Isub2ind(unsigned const int *arrayOfDimensions, unsigned const int *arrayOfSubscripts, unsigned const int dimensions);
void Iind2sub(unsigned const int *arrayOfDimensions, unsigned const int dimensions, unsigned const int index, unsigned int convertedIndex[]);

#endif
