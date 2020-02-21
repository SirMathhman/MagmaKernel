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

