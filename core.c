//
// Created by SirMathhman on 2/20/2020.
//

#include "stdlib.h"
#include "core.h"

Array Array_(int size) {
    Any **block = malloc(sizeof(Any *) * size);
    return Array_native(block, size);
}

void Array$(Array this) {
    free(this.elements);
}

Any *get_Array(Array this, int index) {
    return this.elements[index];
}

void set_Array(Array *this, int index, Any *value) {
    if (index < length_Array(*this)) {
        this->elements[index] = value;
    }
}

int length_Array(Array this) {
    return this.length;
}


Array copy_Array(Array this, int size) {
    int length = length_Array(this);
    Array copy = Array_(size);
    for (int i = 0; i < length; i++) {
        Any *value = get_Array(this, i);
        set_Array(copy, i, value);
    }
    return copy;
}

Array Array_native(Any **elements, int size) {
    Array array = {elements, size};
    return array;
}

bool equals_Object(Array this, Object (*cast)(Any *), Object *other) {
    return cast(get_Array(this, 0)).equals(this, other);
}