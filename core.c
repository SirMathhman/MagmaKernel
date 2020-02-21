//
// Created by SirMathhman on 2/20/2020.
//

#include <stdlib.h>
#include "core.h"

Array Array_(int length) {
    Array result = {malloc(length * sizeof(Any *)), length};
    return result;
}

void Array$(Array *array) {
    free(array->content);
}

Any *get_Array(Array *this, int index) {
    return this->content[index];
}

void set_Array(Array *this, int index, Any *value) {
    this->content[index] = value;
}

int length_Array(Array *this) {
    return this->length;
}

bool equals_Object(Any *this, Object *(*cast)(Any *), Object *other) {
    return cast(this)->equals(this, other);
}
