#include "includes/anagram.h"
#include <string.h>
#include <stdio.h>

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void generateAnagrams(char* str, int start, int end) {
    if (start == end) {
        printf("%s\n", str);
    } else {
        for (int i = start; i <= end; i++) {
            swap((str + start), (str + i));
            generateAnagrams(str, start + 1, end);
            swap((str + start), (str + i));
        }
    }
}

void printAllAnagrams(char* str) {
    int length = strlen(str);
    generateAnagrams(str, 0, length - 1);
}
