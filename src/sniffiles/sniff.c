#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_handler.h"
#include "search.h"
#include "threading.h"
#include "cli.h"

int main(int argc, char *argv[]) {
    char *search_string, *filename, *algo;
    int is_threaded = 0;
    parse_arguments(argc, argv, &search_string, &filename, &algo, &is_threaded);

    if(is_threaded){
        parallel_search(filename, search_string, 4);
        return EXIT_SUCCESS;
    }   

    FILE *file = open_file(filename);
    char line[1024];
    int line_number = 0, found = 0;

    while (read_line(file, line, sizeof(line))) {
        line_number++;

        int match = 0;
        if (strcmp(algo, "boyer-moore") == 0) {
            match = boyer_moore_search(line, search_string);
        } else {
            fprintf(stderr, "Unknown algorithm: %s\n", algo);
            exit(EXIT_FAILURE);
        }

        if (match) {
            printf("Line %d: %s", line_number, line);
            found = 1;
        }
    }

    close_file(file);

    if (!found) {
        printf("No matches found for '%s' in %s\n", search_string, filename);
    }

    return EXIT_SUCCESS;
}
