#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <zlib.h>
#include "png.h"

/*
 * Analyze a PNG file.
 * If it is a PNG file, print out all relevant metadata and return 0.
 * If it isn't a PNG file, return -1 and print nothing.
 */
int analyze_png(FILE *f) {
    /* YOU WRITE THIS PART */
    /* 1. Parse Header to validate PNG file
     */
    //size_t crc = crc32(0L, Z_NULL, 0);
    int png_signature[8] = {0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a};
    char signature[8];
    fread(signature, 8, 1, f);
    for (int i = 0; i < 8; i++) {
        if (signature[i] != png_signature[i]) {
            return -1;
        }
    }
    return 0;
}
