/***********************************************************************
 * PortableGrayMap
 * Representation of grayscale image.
 *
 * File format specification: http://netpbm.sourceforge.net/doc/pgm.html
 ***********************************************************************/

#ifndef _PORTABLE_GRAY_MAP_H_
# define _PORTABLE_GRAY_MAP_H_

#include <stddef.h>
#include <stdint.h>

/* Types */

/* File encoding of an image */
typedef enum
{
  ASCII = 2,
  BINARY = 5
} PortableGrayMapType;

/* Representation of a PGM image */
typedef struct
{
  PortableGrayMapType type;
  size_t width;
  size_t height;
  uint16_t maxValue;
  uint16_t** array;
} PortableGrayMap;

/* Functions */

/***********************************************************************
 * Create an image from a file.
 * The image must later be deleted by calling deleteImage().
 *
 * PARAMETER
 * filename     - File name of a pgm image
 *
 * RETURN
 * NULL         - if any error
 * image        - The read image
 ***********************************************************************/
PortableGrayMap* createImageFromFile(const char* filename);

/***********************************************************************
 * Save an image to a file.
 *
 * PARAMETERS
 * image        - The image to save
 * filename     - Destination file name
 ***********************************************************************/
int saveImageToFile(const PortableGrayMap* image, const char* filename);

/***********************************************************************
 * Create an empty image of specified dimension.
 * The image must later be deleted by calling deleteImage().
 *
 * PARAMETERS
 * width        - The width of the image
 * height       - The height of the image
 * numLevels    - Number of gray levels of the image
 *
 * RETURN
 * NULL         - if any error
 * image        - A new image where each pixel is initialized to 0
 ***********************************************************************/
PortableGrayMap* createEmptyImage(size_t width, size_t height, size_t numLevels);

/***********************************************************************
 * Delete an image.
 *
 * PARAMETER
 * image        - The image to destroy.
 ***********************************************************************/
void deleteImage(PortableGrayMap* image);

#endif // !_PORTABLE_GRAY_MAP_H_

