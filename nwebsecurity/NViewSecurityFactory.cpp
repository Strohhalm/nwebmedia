//
// Created by strohhalm on 30.06.15.
//

#include <nwebsecurity/NViewSecurityFactory.h>
#include <nwebsecurity/NSecViewLogin.h>
#include <nwebsecurity/NSecViewRegister.h>

namespace nox
{
    namespace web
    {
        namespace security
        {
            NViewSecurityFactory::NViewSecurityFactory() : INViewFactory(NCOMPONENT_WEB_SECURITY, NXS(NViewSecurityFactory))
            {
            }

            NViewSecurityFactory::~NViewSecurityFactory()
            {
            }

            INView * NViewSecurityFactory::createView(const NString & viewName)
            {
                if (viewName.compare(NXS(NSecViewLogin)) == 0)
                    return new NSecViewLogin();
                if (viewName.compare(NXS(NSecViewRegister)) == 0)
                    return new NSecViewRegister();
                return NULL;
            }
        }
    }
}