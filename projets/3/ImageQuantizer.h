/***********************************************************************
 * ImageQuantizer
 * Interface related to the quantization an image.
 *
 * Notes:
 *  - computeOptimalReduction and quantizeGrayImage functions must be
 *    implemented in ImageQuantizer.c
 *  - A naive version of quantization is given by the quantizeGrayImageNaive
 *    function and is already implemented in ImageQuantizerNaive.c as an 
 *    example.
 ***********************************************************************/

#ifndef _IMAGE_QUANTIZER_H_
# define _IMAGE_QUANTIZER_H_

#include "PortableGrayMap.h"

/***********************************************************************
 * Given an histogram h of size n, where n is the number of gray levels,
 * this function computes k-1 thresholds (p_1, ... p_{k-1}) and 
 * k levels (v_1, ... v_k), with k <= n, such that the resulting mapping
 * function g(i) minimizes the squared error \sum_{i=0}^{n-1} h[i](i-g(i))^2.
 *
 * PARAMETERS
 * histogram        - The histogram vector (h)
 * histogramLength  - Size of the histogram vector (n)
 * reductionLength  - The number of thresholds to compute (k-1)
 * thresholds       - An allocated vector of size k-1 where the computed
 *                    thresholds (p_1, ..., p_{k-1}) will be stored
 * levels           - An allocated vector of size k where the computed levels
 *                    (v_1, ..., v_k) will be stored
 ***********************************************************************/
void computeOptimalReduction(const size_t* histogram, size_t histogramLength,
			     size_t reductionLength, size_t* thresholds,
                             uint16_t* levels);

/***********************************************************************
 * Quantize an image I in k levels of gray such that the quantized
 * image I* minimizes the squared error.
 * \sum_{i = 1}^height \sum_{j = 1}^width (I[i,j] - I*[i,j])^2
 *
 * This function does not affect the original image.
 *
 * PARAMETERS
 * image            - The image to quantize
 * numLevels        - The new number of gray levels (k)
 *
 * RETURN
 * NULL             - if any error
 * image            - The quantized image in k level
 ***********************************************************************/
PortableGrayMap* quantizeGrayImage(const PortableGrayMap* image, size_t numLevels);

/***********************************************************************
 * Quantize an image in k levels of gray.
 *
 * This function does not affect the original image.
 *
 * PARAMETERS
 * image            - The image to quantize
 * numLevels        - The new number of gray levels (k)
 *
 * RETURN
 * NULL             - if any error
 * image            - The quantized image in k level
 ***********************************************************************/
PortableGrayMap* quantizeGrayImageNaive(const PortableGrayMap* image, size_t numLevels);

#endif // !_IMAGE_QUANTIZER_H_

