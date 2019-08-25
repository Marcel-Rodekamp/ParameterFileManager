//
// Created by Marcel Rodekamp on 25. Aug, 2019
// email: marcel.rodekamp@gmail.com
//
#ifndef USER_LEVEL_PARAMETER_LIST_H
#define USER_LEVEL_PARAMETER_LIST_H

#include "ParameterBase/parameterBase.h"
#include "Parameter/parameter.h"
#include "ParameterList/parameterList.h"

class UserParamList : virtual public ParameterList {
    public:
        Parameter<int> intParameter;
        Parameter<float> floatParameter;
        Parameter<double> doubleVectorParameter;
        Parameter<std::string> stringParameter;


        UserParamList(){
            this->addParameter(this->intParameter, "Int Parameter");
            this->addParameter(this->floatParameter, "Float Parameter");
            this->addParameter(this->doubleVectorParameter, "Double Vector Parameter");
            this->addParameter(this->stringParameter, "String Parameter");
        }

        // NOTE: Further user defined methods are put here
};

#endif //USER_LEVEL_PARAMETER_LIST_H
