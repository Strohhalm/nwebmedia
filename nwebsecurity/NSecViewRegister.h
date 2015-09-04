//
// Created by strohhalm on 12.07.15.
//

#ifndef NSECVIEWREGISTER_H
#define NSECVIEWREGISTER_H

#include <nweb/INView.h>
#include <nwebsecurity/NWebSecurity.h>

namespace nox
{
    namespace web
    {
        namespace security
        {
            class NSecViewRegister : public INView
            {
            protected:
                Wt::WLineEdit * m_ledUsername;
                Wt::WLineEdit * m_ledPassword;
                Wt::WLineEdit * m_ledPasswordCheck;
                Wt::WLineEdit * m_ledFirstName;
                Wt::WLineEdit * m_ledLastName;
                Wt::WLineEdit * m_ledEmail;
            public:
                NSecViewRegister();
                NSecViewRegister(INView * parent);
                virtual ~NSecViewRegister();
                virtual void onRegister();
                virtual void onCancel();
                virtual nint compareTo(const INObject * other) const;
            protected:
                virtual void createContent();
            };
        }
    }
}


#endif //NSECVIEWREGISTER_H
