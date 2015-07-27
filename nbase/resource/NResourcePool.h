//
// Created by strohhalm on 09.06.15.
//

#ifndef NRESOURCEPOOL_H
#define NRESOURCEPOOL_H

#include <nbase/INSingleton.h>
#include <nbase/collection/NList.h>
#include <nbase/resource/INResource.h>
#include <nbase/NAssert.h>

using namespace nox::collection;

namespace nox
{
    namespace resource
    {
        class NResourcePool : public INSingleton<NResourcePool>
        {
            friend class INSingleton<NResourcePool>;
        public:
            template<class RESOURCE>
            static RESOURCE * getResource(const NString & fileName)
            {
                return getInstance()->loadResource<RESOURCE>(fileName);
            }
            template<class RESOURCE>
            static RESOURCE * getResource(const NString & fileName, const NString &suffix)
            {
                return getInstance()->loadResource<RESOURCE>(fileName, suffix);
            }
            template<class RESOURCE>
            static INList<RESOURCE *> * getResources(const NString & fileName)
            {
                return getInstance()->loadResources<RESOURCE>(fileName);
            }
            template<class RESOURCE>
            static INList<RESOURCE *> * getResources(const NString & fileName, const NString &suffix)
            {
                return getInstance()->loadResources<RESOURCE>(fileName, suffix);
            }
        protected:
            NResourcePool();
            virtual ~NResourcePool();
            virtual INList<NString *> * findFiles(const NString & fileName, const NString &suffix);
            virtual INList<NString *> * findFiles(const bfs::path & path, const NString & fileName, const NString &suffix);
        public:
            template<class RESOURCE>
            RESOURCE * loadResource(const NString & fileName)
            {
                return loadResource<RESOURCE>(fileName, "*");
            }
            template<class RESOURCE>
            RESOURCE * loadResource(const NString & fileName, const NString & suffix)
            {
                NStaticAssert(!is_pointer<RESOURCE>::value);
                NStaticAssertBaseOf(INResource, RESOURCE);

                RESOURCE          * result   = NULL;
                INList<NString *> * fileList = findFiles(fileName, suffix);
                if (fileList != NULL)
                {
                    if (fileList->getSize() > 0)
                    {
                        if (fileList->getSize() > 1)
                        {
                            for (int i = 0; i < fileList->getSize(); i++)
                                if (fileList->get(i) != NULL)
                                    delete fileList->get(i);
                            delete fileList;

                            throw NRuntimeException("More than one resource found with the same name");
                        }

                        try
                        {
                            result = new RESOURCE(*fileList->get(0));
                        }
                        catch (NException & exp)
                        {
                            result = NULL;
                        }

                        for (int i = 0; i < fileList->getSize(); i++)
                            if (fileList->get(i) != NULL)
                                delete fileList->get(i);
                    }
                    delete fileList;
                }
                return result;
            }
            template<class RESOURCE>
            INList<RESOURCE *> * loadResources(const NString & fileName)
            {
                return loadResources<RESOURCE>(fileName, "*");
            }
            template<class RESOURCE>
            INList<RESOURCE *> * loadResources(const NString & fileName, const NString & suffix)
            {
                NStaticAssert(!is_pointer<RESOURCE>::value);
                NStaticAssertBaseOf(INResource, RESOURCE);

                INList<RESOURCE *> * resultList = NULL;
                INList<NString *>  * fileList   = findFiles(fileName, suffix);
                if (fileList != NULL)
                {
                    if (fileList->getSize() > 0)
                    {
                        resultList = new NList<RESOURCE *>();
                        for (int i = 0; i < fileList->getSize(); i++)
                        {
                            if (fileList->get(i) != NULL)
                            {
                                try
                                {
                                    resultList->add(new RESOURCE(*fileList->get(i)));
                                }
                                catch (NException & exp)
                                {

                                }
                                delete fileList->get(i);
                            }
                        }
                    }
                    delete fileList;
                }
                return resultList;
            }
            virtual nint compareTo(const INObject * other) const;
        };
    }
}

#endif //NRESOURCEPOOL_H
