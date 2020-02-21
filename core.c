//
// Created by SirMathhman on 2/20/2020.
//

#include <stdlib.h>
#include "core.h"

Array Array_(int length) {
    Array result = {malloc(length * sizeof(Object *)), length};
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

bool equals_Object(Object *this, Object *other) {
    bool (*equals)(void *, struct Object *) = this->equals;
    if (equals == NULL) {
        return false;
    } else {
        return equals(this, other);
    }
}

bool hashCode_Object(Object *this) {
    int (*hashCode)(void *) = this->hashCode;
    if (hashCode == NULL) {
        return 0;
    } else {
        return hashCode(this);
    }
}

string toString_Object(Object *this) {
    string (*toString)(void *) = this->toString;
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

long id_Object(Object *this) {
    return this->id;
}

Object Object_(long id, bool (*equals)(Any *, struct Object *), int (*hashCode)(Any *),
               string (*toString)(Any *)) {
    Object this = {id, equals, hashCode, toString};
    return this;
}

void throw(Object *value) {
    _thrown = value;
}

bool catch(void (*action)(Object *)) {
    if (_thrown == NULL) {
        return true;
    } else {
        action(_thrown);
        return false;
    }
}

void forEach_Array(Array *this, void (*action)(Any *)) {
    for (int i = 0; i < length_Array(this); ++i) {
        Object *object = get_Array(this, i);
        action(object);
    }
}

void map_Array(Array *this, Any *(*mapper)(Any *)) {
    for (int i = 0; i < length_Array(this); ++i) {
        Any **item = get_Array(this, i);
        set_Array(this, i, mapper(item));
    }
}

