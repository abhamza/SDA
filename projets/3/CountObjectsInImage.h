/***********************************************************************
 * CountObjectsInImage
 * Interface of the function countObjectsInImage.
 ***********************************************************************/

#ifndef _COUNT_OBJECTS_IN_IMAGE_H_
# define _COUNT_OBJECTS_IN_IMAGE_H_

/***********************************************************************
 * Count the number of objects in the given image I. A pixel I[i,j] is
 * part of an object if its intensity is greater than the given threshold
 * (i.e., I[i,j] > threshold). Two pixels are considered as part of the
 * same object if there are neighbors.
 *
 * PARAMETERS
 * image        - The image I
 * threshold    - The threshold that determines pixels of interest
 ***********************************************************************/
size_t countObjectsInImage(const PortableGrayMap* image, uint16_t threshold);

#endif // !_COUNT_OBJECTS_IN_IMAGE_H_

