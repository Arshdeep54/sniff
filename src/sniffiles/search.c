#include "search.h"
#include <string.h>

#define PRIME 101

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

void compute_lps(const char* pattern, int pattern_len, int* lps) {
    int length = 0;
    lps[0] = 0;
    int i = 1;
    while (i < pattern_len) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int kmp_search(const char* text, const char* pattern) {
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);
    if (pattern_len > text_len) return 0;

    int lps[pattern_len];
    compute_lps(pattern, pattern_len, lps);
    
    int i = 0, j = 0;
    while (i < text_len) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == pattern_len) return 1;
        else if (i < text_len && pattern[j] != text[i]) {
            j ? j = lps[j - 1] : i++;
        }
    }
    return 0;
}

int rabin_karp_search(const char* text, const char* pattern) {
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);
    if (pattern_len > text_len) return 0;
    
    int hash_text = 0, hash_pattern = 0, h = 1;
    for (int i = 0; i < pattern_len - 1; i++)
        h = (h * 256) % PRIME;
    
    for (int i = 0; i < pattern_len; i++) {
        hash_pattern = (256 * hash_pattern + pattern[i]) % PRIME;
        hash_text = (256 * hash_text + text[i]) % PRIME;
    }
    
    for (int i = 0; i <= text_len - pattern_len; i++) {
        if (hash_pattern == hash_text) {
            int j;
            for (j = 0; j < pattern_len; j++)
                if (text[i + j] != pattern[j]) break;
            if (j == pattern_len) return 1;
        }
        if (i < text_len - pattern_len) {
            hash_text = (256 * (hash_text - text[i] * h) + text[i + pattern_len]) % PRIME;
            if (hash_text < 0) hash_text += PRIME;
        }
    }
    return 0;
}
