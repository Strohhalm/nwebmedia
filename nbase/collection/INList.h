//
// Created by strohhalm on 27.05.15.
//

#ifndef INLIST_H
#define INLIST_H

#include "../INObject.h"

namespace nox
{
    namespace collection
    {
        template<class TYPE>
        class NOX_BASE_API INList : public INObject
        {
        public:
            INList() : INObject() { }
            INList(const INList & other) : INObject() { }
            virtual ~INList() { }
            virtual void add(TYPE value) = 0;
            virtual void insert(TYPE value, long index) = 0;
            virtual void remove(TYPE value) = 0;
            virtual void removeAt(long index) = 0;
            virtual void clear() = 0;
            virtual TYPE get(long index) const = 0;
            virtual TYPE operator[] (long index) const = 0;
            virtual bool contains(TYPE value) const = 0;
            virtual long indexOf(TYPE value) const = 0;
            virtual long getSize() const = 0;
        };
    }
}

#endif //INLIST_H
