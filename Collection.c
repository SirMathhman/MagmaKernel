//
// Created by SirMathhman on 2/20/2020.
//

#include "math.h"
#include "stddef.h"
#include "Throwable.h"
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
        throw(Throwable_Object(Throwable_("Index out of bounds.")));
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
    if (isEmpty_Vector(this, cast)) {
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

bool isEmpty_Vector(Any *this, Vector *(*cast)(Any *)) {
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

Optional Optional_empty() {
    return Optional_of(NULL);
}

Optional Optional_of(Object *value) {
    Object Object = Object_(Optional_ID, NULL, NULL, NULL);
    Optional result = {Object, value};
    return result;
}

bool isEmpty_Optional(Optional this) {
    return this.value == NULL;
}

bool isPresent_Optional(Optional this) {
    return !isEmpty_Optional(this);
}

Object *get_Optional(Optional this) {
    return this.value;
}

Object *getOrElse_Optional(Optional this, Any *other) {
    if (isEmpty_Optional(this)) {
        return other;
    } else {
        return this.value;
    }
}

Object *getOrThrow_Optional(Optional this) {
    if (isEmpty_Optional(this)) {
        throw(Throwable_Object(Throwable_("No such element present.")));
        return NULL;
    } else {
        return get_Optional(this);
    }
}








