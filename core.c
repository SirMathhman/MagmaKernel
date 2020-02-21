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
    bool (*equals)(void *, struct Object *) = cast(this)->equals;
    if (equals == NULL) {
        return false;
    } else {
        return equals(this, other);
    }
}

bool hashCode_Object(Any *this, Object *(*cast)(Any *)) {
    int (*hashCode)(void *) = cast(this)->hashCode;
    if (hashCode == NULL) {
        return 0;
    } else {
        return hashCode(this);
    }
}

string toString_Object(Any *this, Object *(*cast)(Any *)) {
    string (*toString)(void *) = cast(this)->toString;
    if (toString == NULL) {
        /*
         * TODO: default string serialization
         * id + hashCode
         */
        return "";
    } else {
        return toString(this);
    }
}

long id_Object(Any *this, Object *(*cast)(Any *)) {
    return cast(this)->id;
}

Object Object_(long id, bool (*equals)(Any *, struct Object *), int (*hashCode)(Any *),
               string (*toString)(Any *)) {
    Object this = {id, equals, hashCode, toString};
    return this;
}

