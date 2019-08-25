//
// Created by Marcel Rodekamp on 25. Aug, 2019
// email: marcel.rodekamp@gmail.com
//

#include "../ParameterBase/parameterBase.h"
#include "../Parameter/parameter.h"
#include "parameterList.h"
#include "../exampleUserParameter.h"

#define BOOL_STR(b) (b ? "True" : "False")

// TODO: This could be more suffisticated!!!!
bool testParameterList(bool printFlag){
    std::cout << "Testing Parameter List" << std::endl;

    bool testFlag = true;

    UserParamList np;

    if(printFlag){
        std::cout << "Testing readFile() method: " << std::endl;
    }

    std::string fileName = "exampleUserParameter.param";

    np.readFile(fileName);

    if (np.intParameter.getName() != "Int Parameter"){
        testFlag = false;
    }

    if(printFlag){
        std::cout << "The readFile method works for name: " << BOOL_STR(testFlag)
                  << std::endl;
    }

    if(!testFlag){
        return  testFlag;
    }

    if(np.intParameter() != 10){
        testFlag = false;
    }

     if(printFlag){
        std::cout << "The readFile method works for value: " << BOOL_STR(testFlag)
                  << std::endl;
    }

    return testFlag;
}
