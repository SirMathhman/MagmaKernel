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

typedef struct Object {
    long id;

    bool (*equals)(Any *, struct Object *);

    int (*hashCode)(Any *);

    string (*toString)(Any *);
} Object;

Object Object_(long id, bool (*equals)(Any *, struct Object *),
               int (*hashCode)(Any *),
               string (*toString)(Any *));

void Object$(Object *this);

long id_Object(Object *this);

bool equals_Object(Object *this, Object *other);

bool hashCode_Object(Object *this);

string toString_Object(Object *this);

Object *_thrown = NULL;

void throw(Object value);

bool catch(void (*action)(Object));

typedef struct Array {
    Any **content;
    int length;
} Array;

Array Array_(int length);

void Array$(Array *array);

Any *get_Array(Array *this, int index);

void set_Array(Array *this, int index, Any *value);

int length_Array(Array *this);

void forEach_Array(Array *this, void (*action)(Any *));

void map_Array(Array *this, Any *(*mapper)(Any *));

#endif //MAGMAKERNEL_CORE_H
