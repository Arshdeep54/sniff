#include "threading.h"
#include "file_handler.h"
#include "search.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* search_thread(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    FILE* file = open_file(data->filename);

    fseek(file, data->start, SEEK_SET);

    char line[BUFFER_SIZE];
    long current_pos = data->start;
    int line_number = 0;

    while (current_pos < data->end && read_line(file, line, BUFFER_SIZE)) {
        current_pos = ftell(file);
        line_number++;

        if (boyer_moore_search(line, data->pattern)) {  // Use Boyer-Moore
            pthread_mutex_lock(&lock);
            printf("Thread %lu - Line %d: %s", pthread_self(), line_number, line);
            pthread_mutex_unlock(&lock);
        }
    }

    close_file(file);
    return NULL;
}


void parallel_search(const char* filename, const char* pattern, int num_threads) {
    FILE* file = open_file(filename);

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    close_file(file);

    long chunk_size = file_size / num_threads;
    pthread_t threads[num_threads];
    ThreadData thread_data[num_threads];

    for (int i = 0; i < num_threads; i++) {
        thread_data[i].filename = filename;
        thread_data[i].pattern = pattern;
        thread_data[i].start = i * chunk_size;
        thread_data[i].end = (i == num_threads - 1) ? file_size : (i + 1) * chunk_size;

        pthread_create(&threads[i], NULL, search_thread, &thread_data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
}
