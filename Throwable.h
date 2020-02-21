//
// Created by SirMathhman on 2/21/2020.
//

#ifndef MAGMAKERNEL_THROWABLE_H
#define MAGMAKERNEL_THROWABLE_H

#include <stdlib.h>
#include <stddef.h>
#include "core.h"

static const long Throwable_ID = 723654134L;
typedef struct Throwable {
    Object Object;
    char *message;
} Throwable;

Object Throwable_Object(Throwable throwable);

Throwable Throwable_(char *message);

void Throwable$(Object *this, Throwable (*cast)(Object *));

char *getMessage_Throwable(Object *this, Throwable (*cast)(Object *));

#endif //MAGMAKERNEL_THROWABLE_H