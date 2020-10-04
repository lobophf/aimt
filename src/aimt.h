#ifndef AIMT_H
#define AIMT_H

#include "errorsHandler.h"
#include "dimensionsProduct.h"

#define sub2ind(arrayOfDimensions, arrayOfSubscripts, dimensions) ({ \
	inspectSubscripts(__FILE__, __LINE__, arrayOfDimensions, arrayOfSubscripts, dimensions); \
	Isub2ind(arrayOfDimensions, arrayOfSubscripts, dimensions); \
})

#define ind2sub(arrayOfDimensions, dimensions, index, convertedIndex) ({ \
	inspectIndex(__FILE__, __LINE__, arrayOfDimensions, index, dimensions); \
	Iind2sub(arrayOfDimensions, dimensions, index, convertedIndex); \
})

/**
 *
 * @brief Converts subscripts into linear indices. The linear index traverses rows, 
 * then columns, then higher dimensions. The index starts from 1, and the subscripts start 
 * from (1, ..., 1).
 *
 * @param[in] arrayOfDimensions where each element represents the size of each array 
 * dimension. 
 * @param[in] arrayOfSubscripts in which the set of its elements form the position to be 
 * converted.
 * @param[in] dimensions is size of the @paramname{arrayOfDimensions} and 
 * @paramname{arrayOfSubscripts}.
 * @return a converted linear index.
 *
 * @pre The parameter @paramname{dimensions} must be greater than or equal to 2. 
 *
 * @warning Ensure that @paramname{arrayOfDimensions} and @paramname{arrayOfSubscripts} 
 * share the same @paramname{dimension}, in order to get a proper result.
 */
long long Isub2ind(const int *arrayOfDimensions, const int *arrayOfSubscripts, const int dimensions);

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
 * @param[in] arrayOfDimensions where each element represents the number of rows and 
 * columns respectively.
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
void Iind2sub(const int *arrayOfDimensions, const int dimensions, const int index, int convertedIndex[]);

/** 
 *
 * @example demo_ind2sub.c
 * This is an example of how to use the ind2sub function.
 */
#endif
