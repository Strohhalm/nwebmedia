//
// Created by strohhalm on 18.07.15.
//

#include "NCascadingStyleSheetsFile.h"

namespace nox
{
    namespace web
    {
        namespace resource
        {
            NCascadingStyleSheetsFile::NCascadingStyleSheetsFile(const NString & fileName) : INResource(fileName)
            {
            }

            NCascadingStyleSheetsFile::~NCascadingStyleSheetsFile()
            {
            }

            nint NCascadingStyleSheetsFile::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NCascadingStyleSheetsFile * obj = dynamic_cast<const NCascadingStyleSheetsFile *>(other);

                    if (obj != NULL)
                    {
                        nint result = 0;

                        if ((result = getFilename().compare(obj->getFilename())) == 0)
                        {
                            result = getAbsolutPath().compare(obj->getAbsolutPath());
                        }

                        return result;
                    }
                    else
                    {
                        return 1;
                    }
                }
                catch (bad_cast &)
                {
                    return 1;
                }
            }
        }
    }
}
