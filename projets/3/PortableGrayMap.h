#ifndef _PORTABLE_GRAY_MAP_H_
# define _PORTABLE_GRAY_MAP_H_

#include <stddef.h>
#include <stdint.h>

typedef enum
{
  ASCII = 2,
  BINARY = 5
} PortableGrayMapType;

typedef struct
{
  PortableGrayMapType type;
  size_t width;
  size_t height;
  uint16_t maxValue;
  uint16_t** array;
} PortableGrayMap;

PortableGrayMap* createImageFromFile(const char* filename);
int saveImageToFile(const PortableGrayMap* image, const char* filename);

PortableGrayMap* createEmptyImage(size_t width, size_t height, size_t numLevels);
void deleteImage(PortableGrayMap* image);

#endif // !_PORTABLE_GRAY_MAP_H_

