#include <stdio.h>
#include <stdlib.h>

#include "Comic.h"
#include "PPM.h"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: ./mainSeamCarving input.pnm output.pnm k\n");
        return -1;
    }

    // Load image
    PPMImage* original = readPPM(argv[1]);
    if (!original) {
        fprintf(stderr, "Cannot load image '%s'\n", argv[1]);
        return -1;
    }

    // Seam carving
    int k = atoi(argv[3]);

    PPMImage* new;

    if (k < 0) {
        new = reduceImageWidth(original, (size_t) -k);
    }
    else {
        new = increaseImageWidth(original, (size_t) k);
    }

    if (!new) {
        fprintf(stderr, "Cannot build new image\n");
        freePPM(original);
        return -1;
    }

    // Save and free
    writePPM(argv[2], new);
    freePPM(original);
    freePPM(new);

    return 0;
}
