//
// Created by SirMathhman on 2/20/2020.
//

#ifndef MAGMAKERNEL_COLLECTIONS_H
#define MAGMAKERNEL_COLLECTIONS_H

#include <stdlib.h>
#include "core.h"

#endif //MAGMAKERNEL_COLLECTIONS_H

typedef struct Array {
    Any **elements;
    int length;
} Array;

Array Array_(int size);

void Array$(Array this);

Any *get_Array(Array this, int index);

void set_Array(Array this, int index, Any *value);

int length_Array(Array this);

Array copy_Array(Array this, int size);

typedef struct Vector {
    Array array;
    int size;
} Vector;

Vector Vector_(int size);

void Vector$(Vector this);

void add(Vector this, Any *element);

Any *Vector_get(Vector this, int index);

void set_Vector(Vector this, int index, Any *element);

int Vector_size(Vector this);