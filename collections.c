//
// Created by SirMathhman on 2/20/2020.
//

#include "collections.h"
#include "core.h"

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





