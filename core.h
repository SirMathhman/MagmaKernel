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

Any *_thrown = NULL;

void throw(Any *value);

bool catch(void (*action)(Any *));

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
    long id;

    bool (*equals)(Any *, struct Object *);

    int (*hashCode)(Any *);

    string (*toString)(Any *);
} Object;

Object Object_(long id, bool (*equals)(Any *, struct Object *),
               int (*hashCode)(Any *),
               string (*toString)(Any *));

void Object$(Any *this, Object *(*cast)(Any *this));

long id_Object(Any *this, Object *(*cast)(Any *));

bool equals_Object(Any *this, Object *(*cast)(Any *), Object *other);

bool hashCode_Object(Any *this, Object *(*cast)(Any *));

string toString_Object(Any *this, Object *(*cast)(Any *));

#endif //MAGMAKERNEL_CORE_H
