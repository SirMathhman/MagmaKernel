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
    Any **content;
    int length;
} Array;

Array Array_(int length);

void Array$(Array *array);

Any *get_Array(Array *this, int index);

void set_Array(Array *this, int index, Any *value);

int length_Array(Array *this);

typedef struct Object {
    bool (*equals)(Any *this, struct Object *other);

    int (*hashCode)(Any *this);

    string (*toString)(Any *this);
} Object;

bool equals_Object(Any *this, Object *(*cast)(Any *this), Object *other);

bool hashCode_Object(Any *this, Object *(*cast)(Any *this));

string toString_Object(Any *this, Object *(*cast)(Any *this));

#endif //MAGMAKERNEL_CORE_H
