//
// Created by Marcel Rodekamp on 25. Aug, 2019
// email: marcel.rodekamp@gmail.com
//

#include "parameterBase.h"
#include "../Parameter/parameter.h"
#include "../ParameterList/parameterList.h"

#define BOOL_STR(b) (b ? "True" : "False")

bool testParameterPair(bool printFlag){
    std::cout << "Testing ParameterPair" << std::endl;

    // allocate the different usecases
    std::string textLine1 = "Key = Val";
    std::string textLine2 = "Key = ";
    std::string textLine3 = "";

    bool testFlag = true;

    // test usual case
    if(printFlag){
        std::cout << "Testing standard use case: " << std::endl;
    }

    ParameterPair paraPair1(textLine1);

    if(paraPair1.getKey().compare( "Key" ) != 0 ){
        std::cout << "Key = " << paraPair1.getKey() << std::endl;
        testFlag = false;
    }
    if(paraPair1.getVal().compare( " Val" ) != 0 ){
        std::cout << "Val = " << paraPair1.getVal() << std::endl;
        testFlag = false;
    }

    if(printFlag){
        std::cout << "Standard use case works: " << BOOL_STR(testFlag)
                  << "\n" << std::endl;
    }

    if(!testFlag){
        return testFlag;
    }

    if(printFlag){
        std::cout << "Testing empty value case:: " << std::endl;
    }

    ParameterPair paraPair2(textLine2);

    if(paraPair2.getKey().compare( "Key" ) != 0 ){
        testFlag = false;
    }
    if(paraPair2.getVal().compare( " " ) != 0 ){
        testFlag = false;
    }

    if(printFlag){
        std::cout << "Empty value use case works: " << BOOL_STR(testFlag)
                  << "\n" << std::endl;
    }

    if(!testFlag){
        return testFlag;
    }

    if(printFlag){
        std::cout << "Testing empty line case: " << std::endl;
    }

    try{
        ParameterPair paraPair3(textLine3);
    } catch(int e){
        if(e != 0){
            testFlag = false;
        }
    }

    if(printFlag){
    std::cout << "Empty line use case works: " << BOOL_STR(testFlag)
              << "\n" << std::endl;
    }

    return testFlag;
}

bool testParameterBase(bool printFlag){
    std::cout << "Testing ParameterBase" << std::endl;

    std::string paraName = "name";

    Parameter<float> pb1(paraName, false, 1);

    bool testFlag = true;

    if(printFlag){
        std::cout << "Testing the getName() method: " << std::endl;
    }

    if( pb1.getName().compare( paraName ) != 0 ){
        testFlag = false;
    }

    if(printFlag){
        std::cout << "The getName() method works: " << BOOL_STR(testFlag)
                  << "\n" << std::endl;
    }

    if(!testFlag){
        return testFlag;
    }

    if(printFlag){
        std::cout << "Testing setName() method: " << std::endl;
    }

    std::string name = "newName";
    pb1.setName(name);

    if( pb1.getName().compare( name ) != 0 ){
        testFlag = false;
    }

    if(printFlag){
        std::cout << "The setName() method works: " << BOOL_STR(testFlag) << "\n"
                  << std::endl;
    }

    if(!testFlag){
        return testFlag;
    }

    if(printFlag){
        std::cout << "Testing isOptional() method: " << std::endl;
    }

    if(pb1.isOptional()){
        testFlag = false;
    }

    if(printFlag){
        std::cout << "The isOptional() method works: " << BOOL_STR(testFlag) << "\n"
                  << std::endl;
    }

    if(!testFlag){
        return testFlag;
    }

    if(printFlag){
        std::cout << "Testing isOptional(bool) method: " << std::endl;
    }

    pb1.setOptional(false);

    if(pb1.isOptional()){
        testFlag = false;
    }

    if(printFlag){
        std::cout << "The isOptional() method works: " << BOOL_STR(testFlag) << "\n"
                  << std::endl;
    }

    if(!testFlag){
        return testFlag;
    }

    if(printFlag){
        std::cout << "Testing isSet() method: " << std::endl;
    }

    if(pb1.isSet()){
        testFlag = false;
    }

    if(printFlag){
        std::cout << "The isSet() method works: " << BOOL_STR(testFlag)
                  << "\n" << std::endl;
    }

    if(!testFlag){
        return testFlag;
    }

    if(printFlag){
        std::cout << "Testing isSet(bool) method: " << std::endl;
    }

    pb1.setSet(true);

    if(!pb1.isSet()){
        testFlag = false;
    }

    if(printFlag){
        std::cout << "The isSet(bool) method works: " << BOOL_STR(testFlag) << "\n"
              << std::endl;
}

return testFlag;
}
