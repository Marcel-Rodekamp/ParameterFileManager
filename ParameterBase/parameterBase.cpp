//
// Created by Marcel Rodekamp on 25. Aug, 2019
// email: marcel.rodekamp@gmail.com
//

#include <sstream>

#include "parameterBase.h"
#include "../Parameter/parameter.h"
#include "../ParameterList/parameterList.h"

/****************************************************************************************
 *
 * Function definitions of struct ParameterPair
 *
 ***************************************************************************************/

std::string & ParameterPair::getKey(){
    return this->key;
}

std::string & ParameterPair::getVal(){
    return this->val;
}


/****************************************************************************************
*
* Function definitions of class ParameterBase
*
***************************************************************************************/

std::string & ParameterBase::getName(){
    return _name;
}

void ParameterBase::setName(const std::string & newName){
    _name = newName;
}

bool ParameterBase::isOptional(){
    return _isOptional;
}

void ParameterBase::setOptional(const bool newValue){
    this->_isOptional = newValue;
}

bool ParameterBase::isSet(){
    return this->_isSet;
}

void ParameterBase::setSet(const bool newValue){
    this->_isSet = newValue;
}

bool ParameterBase::initParam( ParameterPair & paramPair ){

    std::stringstream sStream;

    sStream.str(paramPair.getVal());

    return readstream(sStream);
}
