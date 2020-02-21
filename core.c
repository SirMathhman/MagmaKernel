//
// Created by SirMathhman on 2/20/2020.
//

#include "core.h"

bool equals_Object(Any *this, Object *(*cast)(Any *), Object *other) {
    return cast(this)->equals(this, other);
}
