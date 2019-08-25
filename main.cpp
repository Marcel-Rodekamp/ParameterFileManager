//
// Created by Marcel Rodekamp 7/12/19
//

#include <iostream>
#include <string>

#include "ParameterBase/parameterBase.h"
#include "Parameter/parameter.h"
#include "ParameterList/parameterList.h"
#include "exampleUserParameter.h"

#define PREC float

#define BOOL_STR(b) (b ? "True" : "False")

void test(bool printFlag){
    bool testFlag;

    testFlag = testParameterPair(printFlag);
    std::cout << "ParameterPair works: " << BOOL_STR(testFlag) << "\n" << std::endl;

    testFlag = testParameterBase(printFlag);
    std::cout << "ParameterBase works: " << BOOL_STR(testFlag) << "\n" << std::endl;

    testFlag = testParameter(printFlag);
    std::cout << "Parameter works: " << BOOL_STR(testFlag) << "\n" << std::endl;

    testFlag = testParameterList(printFlag);
    std::cout << "Parameter List works: " << BOOL_STR(testFlag) << std::endl;
}

int main(int argc, char const *argv[]) {
    if(false){
        test(false);
        return 0;
    }
    else{
        // create a parameter class defined in exampleUserParameter.h
        UserParamList paramList;

        // read in parameter from file:
        std::string fileName = "../exampleUserParameter.param";
        paramList.readFile(fileName);

        // The explixit characters can be accessed via the following methods:
        std::cout << "IntParam Name = " << paramList.intParameter.getName() // get the name string.
                  << std::endl;

        // read and write values
        std::cout << "0th value of double vector = "
                  << paramList.doubleVectorParameter(1) // get the second element
                  << std::endl;

        // read values
        //std::cout << paramList.doubleVectorParameter[3] // read the 3rd element
        //          << std::endl;

        return 0;
    }
}
