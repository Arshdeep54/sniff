#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <stdio.h>

FILE* open_file(const char* filename);
void close_file(FILE* file);
int read_line(FILE* file, char* buffer, int max_len);

#endif
