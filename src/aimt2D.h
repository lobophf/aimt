#ifndef AIMT2D_H
#define AIMT2D_H

#include "errorsHandler.h"
#include "dimensionsProduct.h"

/**
 *
 * @brief A special two dimensions case that converts subscripts into linear indices. 
 *
 * @param[in] arrayOfDimensions where each element represents the number of rows and 
 * columns respectively.
 * @param[in] arrayOfSubscripts in which the set of its elements form the position to be 
 * converted.
 * @return a converted linear index for two dimensions case.
 *
 * @pre Each element of @paramname{arrayOfSubscripts} must fit in the each element of the
 * @paramname{arrayOfDimensions}.
 * 
 * @warning Ensure that the @paramname{arrayOfDimensions} and @paramname{arrayOfSubscripts} 
 * have two dimensions, in order to get a proper result.
 */
int sub2ind2D(const int *arrayOfDimensions, const int *arrayOfSubscripts);

/**
 *
 * @brief A special two dimensions case that converts linear index into subscripts. 
 *
 * @param[in] arrayOfDimensions where each element represents the number of rows and 
 * columns respectively.
 * @param[in] index to be converted.
 * @param[in, out] convertedIndex give the converted subscripts set.
 * 
 * @pre The @paramname{index} must fit in the @paramname{arrayOfDimensions}.
 * @pre Each element of @paramname{arrayOfSubscripts} must fit in the each element of the
 * @paramname{arrayOfDimensions}.
 * 
 * @warning Ensure that the @paramname{arrayOfDimensions} and @paramname{convertedIndex} 
 * have two dimensions, in order to get a proper result.
 */
void ind2sub2D(const int *arrayOfDimensions, const int index, int convertedIndex[]);

#endif
