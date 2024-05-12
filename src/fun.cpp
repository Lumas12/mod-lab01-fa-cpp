// Copyright 2022 UNN-IASR
#include "fun.h"
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstring>

unsigned int countWords(const char *const str) {
    return std::count_if(str, str + std::strlen(str), [](char c) {
        return !std::isspace(c);
    });
}

unsigned int faStr1(const char *const str) {
    unsigned int count = 0;
    bool inWord = false;

    for (const char *ptr = str; *ptr; ++ptr) {
        if (!inWord && !std::isdigit(*ptr)) {
            inWord = true;
            ++count;
        } else if (inWord && std::isspace(*ptr)) {
            inWord = false;
        }
    }

    return count;
}

unsigned int faStr2(const char *const str) {
    unsigned int count = 0;
    bool newWord = true;

    for (const char *ptr = str; *ptr; ++ptr) {
        if (newWord && std::isupper(*ptr)) {
            ++count;
            newWord = false;
        } else if (std::isspace(*ptr)) {
            newWord = true;
        }
    }

    return count;
}

unsigned int faStr3(const char *const str) {
    unsigned int sumLength = 0;
    unsigned int wordCount = 0;
    bool inWord = false;

    for (const char *ptr = str; *ptr; ++ptr) {
        if (!inWord && !std::isspace(*ptr)) {
            inWord = true;
            ++wordCount;
        }
        if (inWord && !std::isspace(*ptr)) {
            ++sumLength;
        }
        if (inWord && (std::isspace(*ptr) || !*(ptr + 1))) {
            inWord = false;
        }
    }

    return sumLength / wordCount;
}
