//
// Created by SirMathhman on 2/20/2020.
//

#ifndef MAGMAKERNEL_COLLECTIONS_H
#define MAGMAKERNEL_COLLECTIONS_H

#include <stdlib.h>
#include "core.h"

typedef struct Vector {
    Array array;
    int size;
} Vector;

Vector Vector_(int size);

Vector Vector_empty();

Vector Vector_native(Array array, int size);

void Vector$(Vector this);

Any *first_Vector(Vector vector);

Any *last_Vector(Vector vector);

void add_Vector(Vector *this, Any *element);

bool full_Vector(Vector vector);

void expand_Vector(Vector *this);

Any *get_Vector(Vector this, int index);

void set_Vector(Vector this, int index, Any *element);

int size_Vector(Vector this);

void forEach_Vector(Vector this, Array instances, void (*action)(Array, Any *));

typedef struct VectorMap {
    Vector *keys;
    Vector *values;
} VectorMap;


#endif //MAGMAKERNEL_COLLECTIONS_H