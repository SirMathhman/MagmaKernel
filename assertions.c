//
// Created by SirMathhman on 2/20/2020.
//

#include "assertions.h"

char *assertionName;

void setup(string name) {
    assertionName = name;
}

void pass() {
    printf("%s", assertionName);
    printf("%s", " has passed.");
}

void fail() {
    printf("%s", assertionName);
    printf("%s", " has failed.");
}

void assertFalse(bool value) {
    if (value) {
        fail();
    } else {
        pass();
    }
}

void assertTrue(bool value) {
    if (value) {
        pass();
    } else {
        fail();
    }
}

void assertSame(any *value0, any *value1) {
    if (value0 == value1) {
        pass();
    } else {
        fail();
    }
}

void assertIntEquals(int value0, int value1) {
    if (value0 == value1) {
        pass();
    } else {
        fail();
    }
}

void assertShortEquals(short value0, short value1) {
    if (value0 == value1) {
        pass();
    } else {
        fail();
    }
}

void assertLongEquals(long value0, long value1) {
    if (value0 == value1) {
        pass();
    } else {
        fail();
    }
}

void assertFloatEquals(float value0, float value1) {
    if (value0 == value1) {
        pass();
    } else {
        fail();
    }
}

void assertDoubleEquals(double value0, double value1) {
    if (value0 == value1) {
        pass();
    } else {
        fail();
    }
}

void assertCharEquals(char value0, char value1) {
    if (value0 == value1) {
        pass();
    } else {
        fail();
    }
}
