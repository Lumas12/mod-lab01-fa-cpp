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
    return std::count_if(str, str + std::strlen(str), [](char c) {
        return std::isdigit(c);
    }) == 0 ? countWords(str) : 0;
}

unsigned int faStr2(const char *const str) {
    return std::count_if(str, str + std::strlen(str), [](char c) {
        return std::isupper(c);
    });
}

unsigned int faStr3(const char *const str) {
    unsigned int wordCount = countWords(str);
    unsigned int charCount = std::count_if(str, str + std::strlen(str), [](char c) {
        return !std::isspace(c);
    });
    return std::round(static_cast<double>(charCount) / wordCount);
}
