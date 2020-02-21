//
// Created by SirMathhman on 2/20/2020.
//

#include "stdio.h"
#include "collections.h"

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

void set_Array(Array this, int index, Any *value) {
    if (index < length_Array(this)) {
        this.elements[index] = value;
    }
}

int length_Array(Array this) {
    return this.length;
}

Vector Vector_native(Array array, int size) {
    Vector toReturn = {array, size};
    return toReturn;
}

void Vector$(Vector this) {
    Array$(this.array);
}

void check_Vector(Vector *this) {
    if (full_Vector(*this)) {
        expand_Vector(this);
    }
}

void add_Vector(Vector *this, Any *element) {
    check_Vector(this);
    int size = size_Vector(*this);
    set_Vector(*this, size, element);
    this->size = this->size + 1;
}

int size_Vector(Vector this) {
    return this.size;
}

Any *get_Vector(Vector this, int index) {
    return get_Array(this.array, index);
}

void set_Vector(Vector this, int index, Any *element) {
    set_Array(this.array, index, element);
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

Vector Vector_(int size) {
    return Vector_native(Array_(10), size);
}

Vector Vector_empty() {
    return Vector_native(Array_(10), 0);
}

bool full_Vector(Vector vector) {
    return size_Vector(vector) == length_Array(vector.array);
}

Any *first_Vector(Vector vector) {
    return get_Vector(vector, 0);
}

Any *last_Vector(Vector vector) {
    int lastIndex = size_Vector(vector) - 1;
    return get_Vector(vector, lastIndex);
}

void expand_Vector(Vector *this) {
    int oldCapacity = length_Array(this->array);
    Array newArray = copy_Array(this->array, oldCapacity * 2);
    int oldSize = size_Vector(*this);
    Array$(this->array);
    this->array = newArray;
    this->size = oldSize;
}

void forEach_Vector(Vector this, Array instances, void (*action)(Array, Any *)) {
    for (int i = 0; i < size_Vector(this); i++) {
        void *element = get_Vector(this, i);
        action(instances, element);
    }
}





