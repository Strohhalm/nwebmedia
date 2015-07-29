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

#include <pugixml.hpp>

namespace bfs=boost::filesystem;
using namespace std;
using namespace std::chrono;

#define NOX_BASE_API

#endif //NBASE_H
