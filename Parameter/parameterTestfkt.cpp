//
// Created by Marcel Rodekamp on 25. Aug, 2019
// email: marcel.rodekamp@gmail.com
//

#include "../ParameterBase/parameterBase.h"
#include "../Parameter/parameter.h"
#include "../ParameterList/parameterList.h"

#define BOOL_STR(b) (b ? "True" : "False")

bool testParameter(bool printFlag){
    std::cout << "Testing Parameter" << std::endl;

    bool testFlag = true;

    std::string paramName = "Name";
    Parameter<float> paramReq(paramName, true, 1);
    Parameter<float> paramNonReq(paramName, false, 1);
    Parameter<float> paramSize(paramName, true, 10);

    if(printFlag){
        std::cout << "Testing numberOfValues() method: " << std::endl;
    }

    if(paramReq.numberOfValues() != 1){
        testFlag = false;
    }
    if(paramSize.numberOfValues() != 10){
        testFlag = false;
    }

    if(printFlag){
        std::cout << "The numberOfValues() method works: " << BOOL_STR(testFlag) << "\n"
                  << std::endl;
    }

    if(!testFlag){
        return testFlag;
    }

    if(printFlag){
        std::cout << "Testing operator (): " << std::endl;
    }

    paramReq(0) = 1;
    for(size_t i = 0; i < 10; ++i){
        paramSize(i) = i;
    }

    if(paramReq(0) != 1){
        testFlag = false;
    }

    for(size_t i = 0; i < 10; ++i){
        if(paramSize(i) != i){
            testFlag = false;
        }
    }

    if(printFlag){
        std::cout << "The operator () works: " << BOOL_STR(testFlag) << "\n" << std::endl;
    }

    if(!testFlag){
        return testFlag;
    }

    if(printFlag){
        std::cout << "Testing operator []: " << std::endl;
    }

    if(paramReq[0] != 1){
        testFlag = false;
    }

    for(size_t i = 0; i < 10; ++i){
        if(paramSize[i] != (float) i){
            testFlag = false;
        }
    }

    if(printFlag){
        std::cout << "The operator [] works: " << BOOL_STR(testFlag) << "\n" << std::endl;
    }

    if(!testFlag){
        return testFlag;
    }

    if(printFlag){
        std::cout << "Testing initParam() method: " << std::endl;
    }

    std::string newParamName = "Name";
    std::string wrongParamName = "gsafddadf";
    std::string paramValue = "1.5";
    std::string paramValue2 = "0.0";
    std::string paramValues = "1.5 2.5 3.5 4.5 5.5 6.5 7.5 8.5 9.5 10.5";

    std::string line = newParamName + " = " + paramValue;
    ParameterPair pp1(line);

    paramReq.initParam(pp1);

    if(paramReq() != 1.5){
        testFlag = false;
    }

    line = wrongParamName + " = " + paramValue2;
    ParameterPair pp2(line);

    paramReq.initParam(pp2);

    if(paramReq() != 1.5){
        testFlag = false;
    }

    line = newParamName + " = " + paramValues;
    ParameterPair pp3(line);

    paramSize.initParam(pp3);

    for(size_t i = 0; i < 10; ++i){
        if( paramSize(i) != (float) i + 1.5){
            testFlag = false;
        }
    }

    if(printFlag){
        std::cout << "The initParam() method works: " << BOOL_STR(testFlag) << "\n"
                  << std::endl;
    }

    return testFlag;
}
