#include "cli.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void parse_arguments(int argc, char* argv[], char** search_string, char** filename, char** algo,int *is_threaded) {
    if (argc < 3) {
        printf("Usage: %s <search_string> <filename> [--algo=boyer-moore|kmp|rabin-karp] [--threaded]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    *search_string = argv[1];
    *filename = argv[2];

    if (argc > 3) {
        *algo = argv[3] + 7; // Extract algorithm name from "--algo="
    } else {
        *algo = "boyer-moore"; // Default
    }

    if (argc > 4) {
        if (strcmp(argv[4], "--threaded") == 0) {
            *is_threaded = 1;
        }
    }
}
