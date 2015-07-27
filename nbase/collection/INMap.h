//
// Created by strohhalm on 30.05.15.
//

#ifndef INMAP_H
#define INMAP_H

#include "INList.h"

namespace nox
{
    namespace collection
    {
        template<class KEY, class VALUE>
        class INMap : public INObject
        {
        public:
            INMap() : INObject() { }
            INMap(const INMap &other) : INObject() { }
            virtual ~INMap() { }
            virtual long getSize() const = 0;
            virtual bool isEmpty() const = 0;
            virtual void add(KEY key, VALUE value) = 0;
            virtual void remove(KEY key) = 0;
            virtual void removeAll() = 0;
            virtual bool contains(KEY key) const = 0;
            virtual VALUE get(KEY key) const = 0;
            virtual VALUE operator[](KEY key) const = 0;
            virtual INList<KEY> * getKeyList() = 0;
            virtual nint compareTo(const INObject * other) const = 0;
        };
    }
}


#endif //INMAP_H
