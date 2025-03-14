#ifndef THREADING_H
#define THREADING_H

#include <pthread.h>

typedef struct {
    const char* filename;
    const char* pattern;
    long start;
    long end;
} ThreadData;

void parallel_search(const char* filename, const char* pattern, int num_threads);

#endif