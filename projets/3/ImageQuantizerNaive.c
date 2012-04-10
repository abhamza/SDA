#include "ImageQuantizer.h"

PortableGrayMap* quantizeGrayImageNaive(const PortableGrayMap* image, size_t numLevels)
{
  if (image == NULL || numLevels == 0)
    return NULL;

  PortableGrayMap* res = createEmptyImage(image->width, image->height, numLevels);
  if (res == NULL)
    return NULL;

  const double ratio = image->maxValue / (double)numLevels;
  for (size_t i = 0; i < res->height; ++i)
    for(size_t j = 0; j < res->width; ++j)
      res->array[i][j] = (uint16_t)(image->array[i][j] / ratio);

  return res;
}

