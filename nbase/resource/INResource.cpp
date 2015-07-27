//
// Created by strohhalm on 08.06.15.
//

#include "INResource.h"

namespace nox
{
    namespace resource
    {
        INResource::INResource(const NString & fileName)
        {
            m_AbsolutePath = new NString(fileName);
            m_FileName     = new NString(bfs::path(fileName).filename().string());
            m_RelativePath = new NString(makeRelative(bfs::path(fileName), bfs::current_path()).string());
        }

        INResource::~INResource()
        {
            if (m_FileName != NULL)
                delete m_FileName;
            if (m_AbsolutePath != NULL)
                delete m_AbsolutePath;
            if (m_RelativePath != NULL)
                delete m_RelativePath;
        }

        const NString & INResource::getFilename() const
        {
            return *m_FileName;
        }

        const NString & INResource::getRelativePath() const
        {
            return *m_RelativePath;
        }

        const NString& INResource::getAbsolutPath() const
        {
            return *m_AbsolutePath;
        }

        bfs::path INResource::makeRelative(bfs::path curPath, bfs::path toRel)
        {
            NString _cPath = curPath.string();
            NString _wPath = toRel.string();

            if (_cPath.find(_wPath) != string::npos)
            {
                _cPath = "." + _cPath.replace(_cPath.find(_wPath), _wPath.length(), "");
            }
            return _cPath;
        }
    }
}
