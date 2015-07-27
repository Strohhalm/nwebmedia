//
// Created by strohhalm on 12.07.15.
//

#include "NInfLocalisationModel.h"


namespace nox
{
    namespace infra
    {
        namespace model
        {
            NInfLocalisationModel::NInfLocalisationModel() : INModel("NOX_INF_LOCALISATION")
            {
                CreateModelColumn(NAME, NString)
                CreateModelColumn(LOCALE, NString)
                CreateModelColumn(TEXT, NString)
            }

            NInfLocalisationModel::NInfLocalisationModel(const NInfLocalisationModel & other) : INModel(other)
            {
                CreateModelColumn(NAME, NString)
                CreateModelColumn(LOCALE, NString)
                CreateModelColumn(TEXT, NString)

                if (other.getName() != NULL)
                    setName(new NString(*other.getName()));
                if (other.getLocale() != NULL)
                    setLocale(new NString(*other.getLocale()));
                if (other.getText() != NULL)
                    setText(new NString(*other.getText()));
            }

            NInfLocalisationModel::~NInfLocalisationModel()
            {
            }

            DefineModelValueFunction(NInfLocalisationModel, NAME, Name, NString)
            DefineModelValueFunction(NInfLocalisationModel, LOCALE, Locale, NString)
            DefineModelValueFunction(NInfLocalisationModel, TEXT, Text, NString)

            nint NInfLocalisationModel::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NInfLocalisationModel * obj = dynamic_cast<const NInfLocalisationModel *>(other);

                    if (obj != NULL)
                    {
                        nint result = 0;
                        if ((result = compare(getName(), obj->getName())) == 0)
                        {
                            if ((result = compare(getLocale(), obj->getLocale())) == 0)
                            {
                                result = compare(getText(), obj->getText());
                            }
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
