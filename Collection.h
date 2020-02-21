//
// Created by SirMathhman on 2/20/2020.
//

#ifndef MAGMAKERNEL_COLLECTION_H
#define MAGMAKERNEL_COLLECTION_H

#include "core.h"

static const long Vector_ID = 89713765L;
typedef struct Vector {
    Object Object;
    Array elements;
    int size;
} Vector;

Vector Vector_empty();

Vector Vector_of(int size);

Any *get_Vector(Any *this, Vector *(*cast)(Any *), int index);

Any *set_Vector(Any *this, Vector *(*cast)(Any *), int index, Any *element);

void add_Vector(Any *this, Vector *(*cast)(Any *), Any *element);

bool removeIndex_Vector(Any *this, Vector *(*cast)(Any *), int index);

bool removeElement_Vector(Any *this, Vector *(*cast)(Any *), Any *element);

bool contains(Any *this, Vector *(*cast)(Any *), Any *element);

void clear(Any *this, Vector *(*cast)(Any *));

bool isEmpty(Any *this, Vector *(*cast)(Any *));

int size_Vector(Any *this, Vector *(*cast)(Any *));

#endif //MAGMAKERNEL_COLLECTION_H