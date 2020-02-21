//
// Created by SirMathhman on 2/20/2020.
//

#ifndef test
#define test
#include "collections.h"
#include "assertions.h"
#include "primitives.h"
#endif

int main() {
    setup("Assertions");
    assertTrue(true);
    assertFalse(false);

    setup("Array");
    Any **block = malloc(sizeof(void *) * 4);
    int x = 10;
    block[0] = &x;
    Array array = Array_native(block, 4);
    assertIntEquals(4, length_Array(array));
    assertIntEquals(10, *(int *) get_Array(array, 0));

    int y = 20;
    set_Array(array, 0, &y);
    assertIntEquals(20, *(int *) get_Array(array, 0));
    Array$(array);

    Array temp = Array_(1);
    set_Array(temp, 0, &x);
    Array other = copy_Array(temp, 2);
    assertIntEquals(x, *(int *) get_Array(other, 0));
    assertIntEquals(2, length_Array(other));
    Array$(temp);
    Array$(other);

    setup("Vector");
    Array s = Array_(2);
    set_Array(s, 0, &x);

    Vector vector = Vector_native(s, 1);
    assertIntEquals(x, *(int *) get_Vector(vector, 0));

    set_Vector(vector, 0, &y);
    assertIntEquals(y, *(int *) get_Vector(vector, 0));
    Vector$(vector);

    Vector o = Vector_(1);
    set_Vector(o, 0, &x);
    assertSame(&x, first_Vector(o));
    assertSame(&x, last_Vector(o));

    assertFalse(full_Vector(o));
   expand_Vector(&o);

    assertIntEquals(20, length_Array(o.array));
    Vector$(o);

    Vector empty = Vector_empty();
    add_Vector(&empty, &x);
    void *first = first_Vector(empty);
    assertIntEquals(x, *(int *) first);
    return 0;
}