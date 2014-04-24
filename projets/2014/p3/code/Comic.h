/* ------------------------------------------------------------------------- *
 * Comic.
 * Interface for packing a comics.
 * ------------------------------------------------------------------------- */

#ifndef _COMICS_H_
#define _COMICS_H_

#include <stddef.h>
#include "PPM.h"

/* ------------------------------------------------------------------------- *
 * Reduce the width of a PPM image to `image->width-k` using the seam carving
 * algorithm.
 *
 * The PPM image must later be deleted by calling freePPM().
 *
 * PARAMETERS
 * image        Pointer to a PPM image
 * k            The number of pixels to be removed (along the width axis)
 *
 * RETURN
 * image        Pointer to a new PPM image
 * NULL         if an error occured
 * ------------------------------------------------------------------------- */
PPMImage* reduceImageWidth(PPMImage* image, size_t k);

/* ------------------------------------------------------------------------- *
 * Increase the width of a PPM image to `image->width+k` using the seam
 * carving algorithm.
 *
 * The PPM image must later be deleted by calling freePPM().
 *
 * PARAMETERS
 * image        Pointer to a PPM image
 * k            The number of pixels to be added (along the width axis)
 *
 * RETURN
 * image        Pointer to a new PPM image
 * NULL         if an error occured
 * ------------------------------------------------------------------------- */
PPMImage* increaseImageWidth(PPMImage* image, size_t k);

/* ------------------------------------------------------------------------- *
 * Compute the optimal positions of the images on the page.
 *
 * The returned array must later be deleted by calling free().
 *
 * PARAMETERS
 * images       An array of images
 * nbImages     The number of images
 * comicWidth   The width of a page
 * comicBorder  The border around images
 *
 * RETURN
 * positions    An array of size nbImages, such that positions[i] corresponds
 *              to the row (starting from 0) of images[i] in the optimal
 *              configuration.
 * NULL         if an error occured
 * ------------------------------------------------------------------------- */
size_t* wrapImages(PPMImage** images, size_t nbImages, size_t comicWidth,
                   size_t comicBorder);

/* ------------------------------------------------------------------------- *
 * Pack images into a single comic image.
 *
 * The returned image must later be deleted by calling freePPM().
 *
 * PARAMETERS
 * images       An array of images
 * nbImages     The number of images
 * comicWidth   The width of a page
 * comicBorder  The border around images
 *
 * RETURN
 * image        The comic image
 * NULL         if an error occured
 * ------------------------------------------------------------------------- */
PPMImage* packComic(PPMImage** images, size_t nbImages, size_t comicWidth,
                    size_t comicBorder);

#endif // _COMICS_H_
