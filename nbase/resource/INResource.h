//
// Created by strohhalm on 08.06.15.
//

#ifndef INRESOURCE_H
#define INRESOURCE_H

#include <nbase/INObject.h>

namespace nox
{
    namespace resource
    {
        class INResource : public INObject
        {
        protected:
            NString * m_FileName;
            NString * m_AbsolutePath;
            NString * m_RelativePath;
        public:
            INResource(const NString & fileName);
            virtual ~INResource();
            virtual const NString & getFilename() const;
            virtual const NString & getAbsolutPath() const;
            virtual const NString & getRelativePath() const;
        protected:
            virtual bfs::path makeRelative(bfs::path curPath, bfs::path toRel);
        };
    }
}

#endif //INRESOURCE_H
