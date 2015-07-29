//
// Created by strohhalm on 09.06.15.
//

#include <nbase/resource/NResourcePool.h>

namespace nox
{
    namespace resource
    {
        NResourcePool::NResourcePool() : INSingleton<NResourcePool>()
        {
        }

        NResourcePool::~NResourcePool()
        {
        }

        INList<NString *> * NResourcePool::findFiles(const NString & fileName, const NString & suffix)
        {
            return findFiles(bfs::current_path(), fileName, suffix);
        }

        INList<NString *> * NResourcePool::findFiles(const bfs::path & path, const NString & fileName, const NString & suffix)
        {
            INList<NString *> * resultList = NULL;
            INList<NString *> * subList    = NULL;

            bfs::directory_iterator iterator(path);
            bfs::directory_iterator end_iterator;
            if (iterator != end_iterator)
            {
                resultList = new NList<NString *>();

                while (iterator != end_iterator)
                {
                    if (bfs::is_directory(iterator->status()))
                    {
                        subList = findFiles(iterator->path(), fileName, suffix);
                        if (subList != NULL)
                        {
                            for (int i = 0; i < subList->getSize(); i++)
                                resultList->add(subList->get(i));
                            delete subList;
                        }
                    }
                    else if (bfs::is_regular_file(iterator->status()))
                    {
                        NString curFileName = iterator->path().filename().string();
                        if (curFileName.find(fileName) != NString::npos)
                        {
                            if (suffix.compare("*") == 0)
                            {
                                resultList->add(new NString(iterator->path().string()));
                            }
                            else
                            {
                                if (curFileName.compare(curFileName.length() - suffix.length(), suffix.length(), suffix) == 0)
                                {
                                    resultList->add(new NString(iterator->path().string()));
                                }
                            }
                        }
                    }
                    iterator++;
                }
            }

            return resultList;
        }

        nint NResourcePool::compareTo(const INObject * other) const
        {
            if (this == other)
                return 0;
            if (this > other)
                return 1;
            return -1;
        }
    }
}
