//
// Created by strohhalm on 16.07.15.
//

#include "NLocalisationPortion.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                NLocalisationPortion::NLocalisationPortion()
                {
                    m_From = new NUnsignedLong();
                    m_Count = new NUnsignedLong();
                }

                NLocalisationPortion::NLocalisationPortion(const NUnsignedLong & from, const NUnsignedLong & count)
                {
                    m_From = new NUnsignedLong(from);
                    m_Count = new NUnsignedLong(count);
                }

                NLocalisationPortion::NLocalisationPortion(const NLocalisationPortion & other)
                {
                    m_From = new NUnsignedLong(*other.m_From);
                    m_Count = new NUnsignedLong(*other.m_Count);
                }

                NLocalisationPortion::NLocalisationPortion(const _NLocalisationPortion & from)
                {
                    m_From = new NUnsignedLong(from.from);
                    m_Count = new NUnsignedLong(from.count);
                }

                NLocalisationPortion::~NLocalisationPortion()
                {
                    if (m_From != NULL)
                        delete m_From;
                    if (m_Count != NULL)
                        delete m_Count;
                }

                void NLocalisationPortion::setFrom(const NUnsignedLong & from)
                {
                    m_From->setValue(from);
                }

                const NUnsignedLong & NLocalisationPortion::getFrom()
                {
                    return *m_From;
                }

                void NLocalisationPortion::setCount(const NUnsignedLong & count)
                {
                    m_Count->setValue(count);
                }

                const NUnsignedLong & NLocalisationPortion::getCount()
                {
                    return *m_Count;
                }

                void NLocalisationPortion::toStruct(_NLocalisationPortion & input)
                {
                    memset(&input, 0, sizeof(_NLocalisationPortion));

                    input.from = getFrom().getValue();
                    input.count = getCount().getValue();
                }
            }
        }
    }
}