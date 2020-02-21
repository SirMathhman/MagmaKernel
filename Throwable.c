//
// Created by SirMathhman on 2/21/2020.
//

#include "Throwable.h"

char *getMessage_Throwable(Object *this, Throwable (*cast)(Object *)) {
    return cast(this).message;
}

Throwable Throwable_(char *message) {
    Object Object = {Throwable_ID, NULL, NULL, NULL};
    Throwable result = {Object, message};
    return result;
}

void Throwable$(Object *this, Throwable (*cast)(Object *)) {
    free(getMessage_Throwable(this, cast));
}

Object Throwable_Object(Throwable throwable) {
    return throwable.Object;
}
