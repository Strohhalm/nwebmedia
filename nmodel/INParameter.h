//
// Created by strohhalm on 05.06.15.
//

#ifndef INPARAMETER_H
#define INPARAMETER_H

#include <nbase/INObject.h>

namespace nox
{
    namespace model
    {
        class INParameter : public INObject
        {
        protected:
            NString * m_Name;
        public:
            INParameter();
            INParameter(const NString &paramName);
            INParameter(const INParameter & other);
            virtual ~INParameter();
            virtual const NString &getName() const;
            virtual size_t getType() const = 0;
            virtual bool isNull() const = 0;
            virtual INParameter * clone() = 0;
        };
    }
}

#endif //INPARAMETER_H
