/* ------------------------------------------------------------------------- *
 * Comic.
 * Interface for packing a comics.
 * ------------------------------------------------------------------------- */

#ifndef _COMICS_H_
#define _COMICS_H_

#include <stddef.h>
#include "PNM.h"

/* ------------------------------------------------------------------------- *
 * Reduce the width of a PNM image to `image->width-k` using the seam carving
 * algorithm.
 *
 * The PNM image must later be deleted by calling freePNM().
 *
 * PARAMETERS
 * image        Pointer to a PNM image
 * k            The number of pixels to be removed (along the width axis)
 *
 * RETURN
 * image        Pointer to a new PNM image
 * NULL         if an error occured
 * ------------------------------------------------------------------------- */
PNMImage* reduceImageWidth(PNMImage* image, size_t k);

/* ------------------------------------------------------------------------- *
 * Increase the width of a PNM image to `image->width+k` using the seam
 * carving algorithm.
 *
 * The PNM image must later be deleted by calling freePNM().
 *
 * PARAMETERS
 * image        Pointer to a PNM image
 * k            The number of pixels to be added (along the width axis)
 *
 * RETURN
 * image        Pointer to a new PNM image
 * NULL         if an error occured
 * ------------------------------------------------------------------------- */
PNMImage* increaseImageWidth(PNMImage* image, size_t k);

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
size_t* wrapImages(PNMImage** images, size_t nbImages, size_t comicWidth,
                   size_t comicBorder);

/* ------------------------------------------------------------------------- *
 * Pack images into a single comic image.
 *
 * The returned image must later be deleted by calling freePNM().
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
PNMImage* packComic(PNMImage** images, size_t nbImages, size_t comicWidth,
                    size_t comicBorder);

#endif // _COMICS_H_
