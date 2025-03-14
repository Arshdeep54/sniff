#ifndef SEARCH_H
#define SEARCH_H

int boyer_moore_search(const char* text, const char* pattern);
int kmp_search(const char* text, const char* pattern);
int rabin_karp_search(const char* text, const char* pattern);

#endif
