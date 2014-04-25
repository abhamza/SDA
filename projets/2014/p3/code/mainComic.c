#include <stdio.h>
#include <stdlib.h>

#include "Comic.h"
#include "PNM.h"

int main(int argc, char* argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: ./mainComic width border comic.pnm image1.pnm image2.pnm ... imageN.pnm\n");
        return -1;
    }

    // Load images
    size_t comicWidth = (size_t) atoi(argv[1]);
    size_t comicBorder = (size_t) atoi(argv[2]);

    PNMImage** images = (PNMImage**) malloc((argc - 4) * sizeof(PNMImage*));
    if (!images) {
        fprintf(stderr, "Unable to allocate memory\n");
        return -1;
    }

    size_t nbImages = argc - 4;

    for (size_t i = 0; i < nbImages; i++) {
        images[i] = readPNM(argv[i + 4]);

        if (!images[i]) {
            for (size_t k = 0; k < i; k++) {
                freePNM(images[k]);
            }

            free(images);
            return -1;
        }
    }

    // Build comic
    PNMImage* comic = packComic(images, nbImages, comicWidth, comicBorder);
    if (!comic) {
        for (size_t k = 0; k < nbImages; k++) {
            freePNM(images[k]);
        }

        free(images);
        return -1;
    }

    writePNM(argv[3], comic);

    // Free
    freePNM(comic);

    for (size_t k = 0; k < nbImages; k++) {
        freePNM(images[k]);
    }

    free(images);

    return 0;
}
