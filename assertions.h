//
// Created by SirMathhman on 2/20/2020.
//

#ifndef MAGMAKERNEL_ASSERTIONS_H
#define MAGMAKERNEL_ASSERTIONS_H

#include <stdio.h>
#include "core.h"
#include "collections.h"


void pass();

void fail();

void setup(string name);

void assertFalse(bool value);

void assertTrue(bool value);

void assertSame(Any *value0, Any *value1);

void assertIntEquals(int value0, int value1);

void assertShortEquals(short value0, short value1);

void assertLongEquals(long value0, long value1);

void assertFloatEquals(float value0, float value1);

void assertDoubleEquals(double value0, double value1);

void assertCharEquals(char value0, char value1);

typedef struct Assertion {
    char *name;

    void (*action)();
} Assertion;

Assertion Assertion_(char *name, void (*action)());

void run_Assertion(Assertion this);

typedef struct AssertionBuilder {
    Vector assertions;
} AssertionBuilder;

void append_AssertionBuilder(AssertionBuilder this, Assertion *assertion);

void assertNull(Any *value);

void assertNotNull(Any *value);

void run(AssertionBuilder builder);

#endif //MAGMAKERNEL_ASSERTIONS_H