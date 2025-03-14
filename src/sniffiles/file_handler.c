#include "file_handler.h"
#include <stdlib.h>
#include <stdio.h>

FILE* open_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return file;
}

void close_file(FILE* file) {
    fclose(file);
}

int read_line(FILE* file, char* buffer, int max_len) {
    if (fgets(buffer, max_len, file) != NULL) {
        return 1;
    }
    return 0;
}
