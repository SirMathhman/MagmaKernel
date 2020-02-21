//
// Created by SirMathhman on 2/20/2020.
//

#include "collections.h"

Array Array_(int size) {
    Any **block = malloc(sizeof(Any *) * size);
    Array result = {block, size};
    return result;
}

void Array$(Array this) {
    free(this.elements);
}

Any **elements(Array this) {
    return *this.elements;
}

Any *get_Array(Array this, int index) {
    return elements(this)[index];
}

void set_Array(Array this, int index, Any *value) {
    if (index < length_Array(this)) {
        elements(this)[index] = value;
    }
}

int length_Array(Array this) {
    return this.length;
}

Vector Vector_(int size) {
    Array array = Array_(size);
    Vector toReturn = {array, size};
    return toReturn;
}

void Vector$(Vector this) {
    Array$(this.array);
}

void add(Vector this, Any *element) {
    int size = Vector_size(this);
    int lastIndex = size - 1;
    Any *lastElement = Vector_get(this, lastIndex);
    if(lastElement == NULL) {
        set_Vector(this, lastIndex, element);
    } else {
        int internalLength = length_Array(this.array);
        Array array = copy_Array(this.array, internalLength * 2);
        set_Array(array, size, element);
        Array$(this.array);
        this.array = array;
    }
}

int Vector_size(Vector this) {
    return this.size;
}

Any *Vector_get(Vector this, int index) {
    return this.array.elements[index];
}

void set_Vector(Vector this, int index, Any *element) {
    set_Array(this.array, index, element);
}

Array copy_Array(Array this, int size) {
    int length = length_Array(this);
    Array copy = Array_(size);
    for (int i = 0; i < length; i++) {
        Any *value = get_Array(copy, i);
        set_Array(copy, i, value);
    }
    return copy;
}






