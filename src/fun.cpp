// Copyright 2022 UNN-IASR
#include "fun.h"
#include <math.h>
#include <ctype.h>

unsigned int countWords(const char *str) {
    int count = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!inWord && !isspace(str[i])) {
            inWord = true;
            count++;
        } else if (inWord && isspace(str[i])) {
            inWord = false;
        }
    }

    return count;
}

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;

    while (*str) {
        if (!inWord && !std::isdigit(*str)) {
            inWord = true;
            ++count;
        } else if (inWord && std::isspace(*str)) {
            inWord = false;
        }
        ++str;
    }

    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool newWord = true;

    while (*str) {
        if (newWord && std::isupper(*str)) {
            ++count;
            newWord = false;
        } else if (std::isspace(*str)) {
            newWord = true;
        }
        ++str;
    }

    return count;
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
