//
// Created by SirMathhman on 2/20/2020.
//

#include "math.h"
#include "stddef.h"
#include "Collection.h"

Vector Vector_empty() {
    return Vector_of(0);
}

Vector Vector_of(int size) {
    Object Object = Object_(Vector_ID, NULL, NULL, NULL);

    //implicit double to integer conversion
    int elementSize = fmax(10, size);
    Array elements = Array_(elementSize);
    Vector result = {Object, elements, size};
    return result;
}

void check(Any *this, Vector *(*cast)(Any *), int index) {
    int elementLength = cast(this)->elements.length;
    if (index < elementLength) {
        throw("IndexOutOfBounds");
    }
}

Any *get_Vector(Any *this, Vector *(*cast)(Any *), int index) {
    check(this, cast, index);
    if (catch(throw)) {
        return get_Array(&cast(this)->elements, index);
    } else {
        return NULL;
    }
}

Any *set_Vector(Any *this, Vector *(*cast)(Any *), int index, Any *element) {
    check(this, cast, index);
    if (catch(throw)) {
        Any *previous = get_Array(this, index);
        set_Array(&cast(this)->elements, index, element);
        return previous;
    } else {
        return NULL;
    }
}

bool contains(Any *this, Vector *(*cast)(Any *), Any *element) {
    if (isEmpty(this, cast)) {
        return false;
    }
    int size = size_Vector(this, cast);
    for (int i = 0; i < size; ++i) {
        void *ith = get_Vector(this, cast, i);
        if (catch(throw)) {
            if (ith == element) {
                return true;
            }
        } else {
            return false;
        }
    }
    return false;
}

bool isEmpty(Any *this, Vector *(*cast)(Any *)) {
    return size_Vector(this, cast) == 0;
}

int size_Vector(Any *this, Vector *(*cast)(Any *)) {
    return cast(this)->size;
}

Any *clearElement(Any *this) {
    return NULL;
}

void clear(Any *this, Vector *(*cast)(Any *)) {
    map_Array(&cast(this)->elements, clearElement);
}

Any *removeIndex_Vector(Any *this, Vector *(*cast)(Any *), int index) {
    Any *previous = get_Vector(this, cast, index);
    Array *elements = &cast(this)->elements;
    for (int i = index + 1; i < length_Array(elements); ++i) {
        Any *element = get_Array(elements, i);
        set_Array(element, i - 1, element);
    }
    return previous;
}


