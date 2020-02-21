//
// Created by SirMathhman on 2/20/2020.
//

#include "primitives.h"

string copy(string value) {
    size_t byteSize = sizeof(char) * (strlen(value) + 1);
    string copy = malloc(byteSize);
    strcpy_s(copy, byteSize, value);
    return copy;
}

string concat(string value0, string value1) {
    size_t cpySize = sizeof(char) * (strlen(value0) + 1);
    size_t catSize = sizeof(char) * (strlen(value0) + strlen(value1) + 1);
    string block = malloc(catSize);
    strcpy_s(block, cpySize, value0);
    strcat_s(block, catSize, value1);
    return block;
}
