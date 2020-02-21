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
    printf("%s", " has passed.\n");
}

void fail() {
    printf("%s", assertionName);
    printf("%s", " has failed.\n");
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

void assertSame(Any *value0, Any *value1) {
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

Assertion Assertion_(char *name, void (*action)()) {
    Assertion result = {name, action};
    return result;
}

void run_Assertion(Assertion this) {
    setup(this.name);
    this.action();
}

void append_AssertionBuilder(AssertionBuilder *this, Assertion *assertion) {
    add_Vector(this->assertions, assertion);
}

void assertNotNull(Any *value) {
    if (value == NULL) {
        fail();
    } else {
        pass();
    }
}

void assertNull(Any *value) {
    if (value == NULL) {
        pass();
    } else {
        fail();
    }
}

AssertionBuilder AssertionBuilder_(Vector *vector) {
    AssertionBuilder result = {vector};
    return result;
}

void bridge(Array instances, void *item) {
    run_Assertion(*(Assertion *) item);
}

void run_AssertionBuilder(AssertionBuilder builder) {
    Array empty = Array_(0);
    forEach_Vector(*builder.assertions, empty, bridge);
    Array$(empty);
}
