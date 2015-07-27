//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_NLOCALISATIONVALUE_H
#define NWEBMEDIA_NLOCALISATIONVALUE_H

#include <nbase/NBase.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                struct _NLocalisationValue
                {
                    nchar Text[255];
                };

                class NLocalisationValue
                {
                protected:
                    NString * m_Text;
                public:
                    NLocalisationValue();
                    NLocalisationValue(const NString & text);
                    NLocalisationValue(const NLocalisationValue & other);
                    NLocalisationValue(const _NLocalisationValue & from);
                    virtual ~NLocalisationValue();
                    virtual void setText(const NString & text);
                    virtual const NString & getText();
                    virtual void toStruct(_NLocalisationValue & input);
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NLOCALISATIONVALUE_H
