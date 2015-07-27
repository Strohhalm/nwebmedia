#ifndef NSERVICEDEFINES_H
#define NSERVICEDEFINES_H

#ifndef PREPARE_STRUCT
    #define PREPARE_STRUCT(STRUCT, TYPE)                                                                        \
        memset(&STRUCT, 0, sizeof(TYPE));                                                                       \
        STRUCT.Control.Size = sizeof(TYPE);
#endif

#ifndef PREPARE_STRUCT_PTR
    #define PREPARE_STRUCT_PTR(STRUCT, TYPE)                                                                    \
        if (STRUCT == NULL)                                                                                     \
            STRUCT = new TYPE();                                                                                \
        memset(STRUCT, 0, sizeof(TYPE));                                                                        \
        STRUCT->Control.Size = sizeof(TYPE);
#endif

#ifndef NSTRING_TO_STRUCT
    #define NSTRING_TO_STRUCT(DEST, VALUE)                                                                      \
        memcpy(DEST, VALUE.c_str(), VALUE.length() * sizeof(nchar));
#endif

#define RegisterServiceFunction(FUNC)                                                                           \
    this->registerFunction(NXS(FUNC), new N##FUNC(this));

#define UnRegisterServiceFunction(FUNC)                                                                         \
    IINServiceCallBack * callBack##FUNC = this->getFunction(NXS(FUNC));                                         \
    if (callBack##FUNC != NULL)                                                                                 \
    {                                                                                                           \
        this->unRegisterFunction(NXS(FUNC));                                                                    \
        delete callBack##FUNC;                                                                                  \
    }                                                                                                           \
    else                                                                                                        \
    {                                                                                                           \
        this->unRegisterFunction(NXS(FUNC));                                                                    \
    }

#define DeclareServiceFunction(SERVICE, FUNC, INPUT, OUTPUT)                                                    \
public:                                                                                                         \
    virtual OUTPUT * FUNC(INPUT * input);                                                                       \
protected:                                                                                                      \
    class N##FUNC : public INServiceCallBack<INPUT, OUTPUT>                                                     \
    {                                                                                                           \
    protected:                                                                                                  \
        SERVICE * m_Parent;                                                                                     \
    public:                                                                                                     \
        N##FUNC(SERVICE * parent) : INServiceCallBack<INPUT, OUTPUT>()                                          \
        {                                                                                                       \
            m_Parent = parent;                                                                                  \
        }                                                                                                       \
        virtual ~N##FUNC()                                                                                      \
        {                                                                                                       \
        }                                                                                                       \
        virtual OUTPUT * callFunction(INPUT * input)                                                            \
        {                                                                                                       \
            return m_Parent->FUNC(input);                                                                       \
        }                                                                                                       \
    };

#endif