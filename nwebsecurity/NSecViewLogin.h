//
// Created by strohhalm on 22.06.15.
//

#ifndef NSECVIEWLOGIN_H
#define NSECVIEWLOGIN_H

#include <nweb/INView.h>
#include <nwebsecurity/NWebSecurity.h>

namespace nox
{
    namespace web
    {
        namespace security
        {
            class NSecViewLogin : public INView
            {
            protected:
                Wt::WLineEdit * m_ledUsername;
                Wt::WLineEdit * m_ledPassword;
            public:
                NSecViewLogin();
                NSecViewLogin(INView * parent);
                virtual ~NSecViewLogin();
                virtual void onLogin();
                virtual void onRegister();
                virtual nint compareTo(const INObject * other) const;
            protected:
                virtual void createView();
            };
        }
    }
}


#endif //NSECVIEWLOGIN_H
