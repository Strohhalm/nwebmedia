//
// Created by strohhalm on 05.06.15.
//

#ifndef NASSERT_H
#define NASSERT_H

#include <nbase/NNullPointerException.h>

#define NAssertNull(VALUE)                                                          \
    if (VALUE == NULL)                                                              \
        throw NNullPointerException(NString(#VALUE).append("is NULL"));

#define NAssertIsBaseOf(FIRST, SECOND, MESSAGE) \
    if (is_base_of<FIRST, SECOND>::value) \
        throw NRuntimeException(MESSAGE);

#define NStaticAssert(...) \
    BOOST_STATIC_ASSERT(__VA_ARGS__)

#define NStaticAssertBaseOf(FIRST, SECOND) \
    NStaticAssert(is_base_of<FIRST, SECOND>::value);

#define NAssert(EXPR, MESSAGE) \
    if (EXPR) \
        throw NRuntimeException(MESSAGE);

#endif //NASSERT_H
