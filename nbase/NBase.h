//
// Created by strohhalm on 29.05.15.
//

#ifndef NBASE_H
#define NBASE_H

#include <string>
#include <typeinfo>
#include <ctime>
#include <chrono>
#include <regex>
#include <csignal>
#include <locale>

#include <boost/thread.hpp>
#include <boost/utility.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits.hpp>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

namespace bfs=boost::filesystem;

#include <pugixml.hpp>

using namespace std;
using namespace std::chrono;

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

#define NOX_BASE_API

#endif //NBASE_H
