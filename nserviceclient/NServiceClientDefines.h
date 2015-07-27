#ifndef NSERVICECLIENTDEFINES_H
#define NSERVICECLIENTDEFINES_H

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

#define DeclareServiceClientIFunction(OUTPUT, INPUT, NAME)                                                      \
    virtual OUTPUT * NAME(INPUT *input) = 0;

#define DeclareServiceClientFunction(OUTPUT, INPUT, NAME)                                                       \
    virtual OUTPUT * NAME(INPUT *input);

#define DefineServiceClientFunction(OUTPUT, INPUT, SERVICE, SERVICE_CLIENT, NAME)                               \
    OUTPUT * SERVICE_CLIENT::NAME(INPUT * input)                                                                \
    {                                                                                                           \
        input->getHead().getControl().setServiceName(NXS(SERVICE));                                             \
        input->getHead().getControl().setFunctionName(NXS(NAME));                                               \
                                                                                                                \
        return this->call<INPUT, OUTPUT>(input);                                                                \
    }                                                                                                           \

#endif