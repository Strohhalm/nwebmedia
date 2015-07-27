//
// Created by strohhalm on 04.06.15.
//

#ifndef INTYPEDRESULTSET_H
#define INTYPEDRESULTSET_H

#include <nbase/INObject.h>
#include <nbase/collection/INList.h>
#include <nbase/collection/NList.h>

using namespace nox::collection;

namespace nox
{
    namespace model
    {
        template<class MODEL>
        class INTypedResultSet : public INObject
        {
        public:
            INTypedResultSet() { }
            virtual ~INTypedResultSet() { }
            virtual MODEL * first() = 0;
            virtual MODEL * previous() = 0;
            virtual MODEL * next() = 0;
            virtual MODEL * last() = 0;
            virtual INList<MODEL* > * all()
            {
                INList<MODEL *> * result = NULL;
                MODEL * row = NULL;

                while ((row = next()) != NULL)
                {
                    if (result == NULL)
                        result = new NList<MODEL *>();
                    result->add(row);
                }

                return result;
            }
            virtual void close() = 0;
        };
    }
}

#endif //INRESULTSET_H
