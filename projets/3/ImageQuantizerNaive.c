#include "ImageQuantizer.h"
#include "math.h"
#include "stdio.h"

PortableGrayMap* quantizeGrayImageNaive(const PortableGrayMap* image, size_t numLevels)
{
  if (image == NULL || numLevels == 0)
    return NULL;

  PortableGrayMap* res = createEmptyImage(image->width, image->height, image->maxValue);
  if (res == NULL)
    return NULL;

  const double sizeInterval = floor((image->maxValue + 1) / (double)(numLevels));
  const double halfsizeInterval = (sizeInterval - 1) / 2.0;
  
  for (size_t i = 0; i < res->height; ++i)
    for(size_t j = 0; j < res->width; ++j)

      res->array[i][j] = (uint16_t)(fmin(numLevels - 1, floor(image->array[i][j]/sizeInterval)) * sizeInterval + halfsizeInterval);

  for (size_t i = 0; i<256; ++i)
    fprintf(stdout,"%d ",(uint16_t)(fmin(numLevels - 1, floor(i/sizeInterval)) * sizeInterval + halfsizeInterval));

  return res;
}

