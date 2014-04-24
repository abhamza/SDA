/* ------------------------------------------------------------------------- *
 * PPM.
 * Interface for loading and writing PPM images.
 *
 * Partly adapted from http://stackoverflow.com/a/2699908
 * ------------------------------------------------------------------------- */

#ifndef _PPM_H_
#define _PPM_H_

#include <stddef.h>


// Types ----------------------------------------------------------------------

typedef struct {
    unsigned char red, green, blue;
} PPMPixel;

typedef struct {
    size_t width;
    size_t height;
    PPMPixel* data;     // Pixel (i, j) is at position i * width + j
} PPMImage;


// Methods --------------------------------------------------------------------

/* ------------------------------------------------------------------------- *
 * Create an empty PPM image.
 * The PPM image must later be deleted by calling freePPM().
 *
 * PARAMETERS
 * width        Width of the image (in pixels)
 * height       Height of the image (in pixels)
 *
 * RETURN
 * image        Pointer to an empty PPM image
 * NULL         if an error occured
 * ------------------------------------------------------------------------- */
PPMImage* createPPM(size_t width, size_t height);

/* ------------------------------------------------------------------------- *
 * Free a PPM image.
 *
 * PARAMETER
 * image        Pointer to a PPM image
 * ------------------------------------------------------------------------- */
void freePPM(PPMImage* image);

/* ------------------------------------------------------------------------- *
 * Load a PPM image from a file.
 * The PPM image must later be deleted by calling freePPM().
 *
 * PARAMETERS
 * filename     Path to the PPM file
 *
 * RETURN
 * image        Pointer to the loaded PPM image
 * NULL         if an error occured
 * ------------------------------------------------------------------------- */
PPMImage* readPPM(char* filename);

/* ------------------------------------------------------------------------- *
 * Write a PPM image into a file.
 *
 * PARAMETERS
 * filename     Path to the PPM file
 * image        Pointer to the PPM image to write
 *
 * RETURN
 * 0            In case of success
 * -1           Otherwise
 * ------------------------------------------------------------------------- */
int writePPM(char* filename, PPMImage* image);

#endif // _PPM_H_
