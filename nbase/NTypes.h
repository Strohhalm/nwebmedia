#ifndef NTYPES_H
#define NTYPES_H

#include <nbase/NBase.h>

typedef string NString;

typedef char   nchar;
typedef unsigned char nuchar;
typedef short nshort;
typedef unsigned short nushort;
typedef int nint;
typedef unsigned int nuint;
typedef long nlong;
typedef unsigned long nulong;
typedef long long nlonglong;
typedef unsigned long long nulonglong;
typedef float nfloat;
typedef double ndouble;
typedef long double nlongdouble;
typedef bool nbool;
typedef size_t nsize;

#define NXS(VALUE) NString(#VALUE)

#endif
