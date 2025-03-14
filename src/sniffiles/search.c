#include "search.h"
#include <string.h>

// Boyer-Moore Search (Optimized for large text)
int boyer_moore_search(const char* text, const char* pattern) {
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);
    
    if (pattern_len > text_len) return 0;

    int bad_char[256];
    for (int i = 0; i < 256; i++) bad_char[i] = -1;
    for (int i = 0; i < pattern_len; i++) bad_char[(unsigned char)pattern[i]] = i;

    int shift = 0;
    while (shift <= (text_len - pattern_len)) {
        int j = pattern_len - 1;
        while (j >= 0 && pattern[j] == text[shift + j]) j--;

        if (j < 0) return 1;
        shift += (j - bad_char[(unsigned char)text[shift + j]] > 1) ? j - bad_char[(unsigned char)text[shift + j]] : 1;
    }
    return 0;
}

