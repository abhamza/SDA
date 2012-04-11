/***********************************************************************
 * ImageQuantizer
 * Interface related to the quantization an image.
 *
 * Notes:
 *  - computeOptimalReduction and quantizeGrayImage functions must be
 *    implemented in ImageQuantizer.c
 *  - A naive version of quantization is given by the quantizeGrayImageNaive
 *    and is already implemented in ImageQuantizerNaive.c as an example.
 ***********************************************************************/

#ifndef _IMAGE_QUANTIZER_H_
# define _IMAGE_QUANTIZER_H_

#include "PortableGrayMap.h"

/***********************************************************************
 * Given an histogram h size n, where n is the number of gray levels,
 * this function compute k optimal thresholds (p_1, ... p_k), with k <= n,
 * such as a mapping function g(i) = v_i iff p_{k-1} <= i < p_k minimize
 * the squared error \sum_{i = O}^{n-1} h[i](i - g(i))^2
 *
 * PARAMETERS
 * histogram        - The histogram vector (h)
 * histogramLength  - Size of the Histogram vector (n)
 * optimalReduction - An allocated vector of size k where the computed thresholds
 *                    (p_1, .., p_k) will be stored
 * reductionLength  - The number of thresholds to compute (k)
 ***********************************************************************/
void computeOptimalReduction(const size_t* histogram, size_t histogramLength,
                             size_t* optimalReduction, size_t reductionLength);

/***********************************************************************
 * Quantize an image I in k levels of gray in such way that the quantized
 * image I* minimize the squared error
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

