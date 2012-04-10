#ifndef _IMAGE_QUANTIZER_H_
# define _IMAGE_QUANTIZER_H_

#include "PortableGrayMap.h"

void computeOptimalReduction(const size_t* histogram, size_t histogramLength,
                             size_t* optimalReduction, size_t reductionLength);

PortableGrayMap* quantizeGrayImage(const PortableGrayMap* image, size_t numLevels);

PortableGrayMap* quantizeGrayImageNaive(const PortableGrayMap* image, size_t numLevels);

#endif // !_IMAGE_QUANTIZER_H_

