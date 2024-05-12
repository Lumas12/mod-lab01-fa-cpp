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



unsigned int faStr2(const char *str) {
    bool inside = false;
    int count = 0;
    int ind = 0;
    while (str[ind]){
        if ((!isspace(str[i]))  && (isspace(str[i - 1])) && (isupper(str[ind]))) {
          count++;
          inside = true;
        }
        i++;
        if (isspace(str[i]))
            inside = false;
        if (((str[i] < 97) || (str[i]>122)))
            if (inside) {
                count--;
                    inWord = false;
            }
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
