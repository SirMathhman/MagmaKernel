//
// Created by SirMathhman on 2/20/2020.
//

#ifndef MAGMAKERNEL_COLLECTIONS_H
#define MAGMAKERNEL_COLLECTIONS_H

#include "core.h"

#endif //MAGMAKERNEL_COLLECTIONS_H

typedef struct Array {
    Any *elements;
    int length;
} Array;

Array Array_(int size);

void Array$(Array this);

Any *get(Array this, int index);

void set(Array this, int index, Any *value);

int size(Array this);

typedef struct Vector {
    Any *elements;
} Vector;

void add(Vector this, Any *element);

Any *Vector_get(Vector this, int index);

void Vector_set(Vector this, int index, Any *element);

int Vector_size(Vector this);