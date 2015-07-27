//
// Created by strohhalm on 10.07.15.
//

#ifndef NWEBMEDIA_NRESULTTYPE_H
#define NWEBMEDIA_NRESULTTYPE_H

namespace nox
{
    namespace model
    {
        enum NResultType
        {
            UNKNOWN = 0,
            STRING = 1,
            BOOL = 2,
            SHORT = 3,
            USHORT = 4,
            INT = 5,
            UINT = 6,
            LONG = 7,
            ULONG = 8,
            DOUBLE = 9,
            DATE = 10,
            TIME = 11,
            DATETIME = 12
        };
    }
}

#endif //NWEBMEDIA_NRESULTTYPE_H
