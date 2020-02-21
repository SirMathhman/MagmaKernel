//
// Created by SirMathhman on 2/20/2020.
//

#include "core.h"

bool equals_Object(Array this, Object (*cast)(Any *), Object *other) {
    return cast(get_Array(this, 0)).equals(this, other);
}