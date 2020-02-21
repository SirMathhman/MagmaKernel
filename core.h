//
// Created by SirMathhman on 2/20/2020.
//

#ifndef MAGMAKERNEL_CORE_H
#define MAGMAKERNEL_CORE_H

typedef char *string;
typedef int bool;
typedef void Any;

#define false 0
#define true 1

typedef struct Array {
    Any **elements;
    int length;
} Array;

Array Array_native(Any **elements, int size);

Array Array_(int size);

void Array$(Array this);

Any *get_Array(Array this, int index);

void set_Array(Array *this, int index, Any *value);

int length_Array(Array this);

Array copy_Array(Array this, int size);

typedef struct Object {
    bool (*equals)(Array this, struct Object *other);
} Object;

bool equals_Object(Array this, Object (*cast)(Any *), Object *other);

#endif //MAGMAKERNEL_CORE_H