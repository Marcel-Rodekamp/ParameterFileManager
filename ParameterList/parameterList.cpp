//
// Created by Marcel Rodekamp on 25. Aug, 2019
// email: marcel.rodekamp@gmail.com
//

#include <fstream>

#include "../ParameterBase/parameterBase.h"
#include "../Parameter/parameter.h"
#include "parameterList.h"

/****************************************************************************************
 *
 * Function definitions of class ParameterList
 *
 ***************************************************************************************/

template <class T>
void ParameterList::addParameter(ParameterPair & pp, bool optional){
    // Create parameter of size 1. If there are more values it will be pushed back in the
    // initParam method
    Parameter<T> param(pp.getKey(), optional, 1);

    // Write values to the parameter
    param.initParam(pp);

    // set the optional bool
    param.setOptional(optional);

    // add parameter to the internal list
    push_back(&param);
}

void ParameterList::addParameter(ParameterBase &paramBase, std::string name, bool optional) {
    // Set the name to the parameter
    paramBase.setName(name);

    // set the optional bool
    paramBase.setOptional(optional);

    // set the parameter into the list
    push_back(&paramBase);
}

void ParameterList::readFile(const std::string fileName){
    // Read the file and add all given Parameters to the ParameterList
    std::fstream file(fileName, std::ios::in);

    if(!file.is_open()){
        std::cerr << "Could not open parameter file :: " << fileName << std::endl;
    }

    std::cout << "Reading parameters from file :: " << fileName << std::endl;

    std::string line;

    while(!file.eof()){
        // read line from file
        getline(file, line);

        // do nothing for lines starting with #
        if(line.empty()){
            continue;
        } else if(line.at(0) == '#'){
            continue;
        }

        // write the parameter values to the parameter if it is in the internal list
        for(auto it = begin(); it != end(); it++){
            // The Parameter Pair devides the string "line" into a key and value
            // stores it as a dictionary type structure
            ParameterPair pp(line);

            if( (*it) -> getName().compare(pp.getKey()) ){
                continue;
            }

            (*it)-> initParam(pp);
        }
    }
}
