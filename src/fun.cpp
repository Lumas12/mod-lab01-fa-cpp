// Copyright 2022 UNN-IASR
#include "fun.h"
#include <math.h>
#include <ctype.h>
#include <cctype>

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool hasDig = false;

    while (*str) {
        if (!inWord &&!isspace(*str)) {
            inWord = true;
            hasDig = false;
        } else if (inWord && isspace(*str)) {
            inWord = false;
            if (!hasDig) {
                ++count;
            }
            hasDig = false;
        } else if (isdigit(*str)) {
            hasDig = true;
        }
        str++;
    }

    if (inWord && !hasDig) {
        ++count;
    }

    return count;
}

unsigned int faStr2(const char *text) {
    int wordCount = 0;
    bool isWithinWord = false;
    bool isFirstCapital = false;
    int position = 0;
    while (text[position]!= '\0') {
        if (isWithinWord && text[position]!= ' ' && text[position] >= 'A' && text[position] <= 'Z') {
            isFirstCapital = false;
        }
        if (!isWithinWord && text[position]!= ' ') {
            isWithinWord = true;
            isFirstCapital = text[position] >= 'A' && text[position] <= 'Z';
        }
        if (isWithinWord && text[position] == ' ') {
            if (isFirstCapital) {
                wordCount++;
            }
            isFirstCapital = false;
            isWithinWord = false;
        }
        position++;
    }
    return wordCount;
}


unsigned int faStr3(const char *str) {
    int count = 0;
    int sumLength = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!inWord && !isspace(str[i])) {
            inWord = true;
            count++;
        }
        if (inWord && !isspace(str[i])) {
            sumLength++;
        }
        if (inWord && (isspace(str[i]) || str[i + 1] == '\0')) {
            inWord = false;
        }
    }

    return round(static_cast<double>(sumLength) / count);
}
