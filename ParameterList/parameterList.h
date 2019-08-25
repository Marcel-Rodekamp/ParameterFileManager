//
// Created by Marcel Rodekamp on 25. Aug, 2019
// email: marcel.rodekamp@gmail.com
//

#ifndef PARAMETER_LIST_H
#define PARAMETER_LIST_H

#include <list>

#include "../ParameterBase/parameterBase.h"
#include "../Parameter/parameter.h"

bool testParameterList(bool printFlag);

class ParameterList : protected std::list<ParameterBase*>{
    private:
        // there is a internal list of ParameterBase pointer

    public:
        template <class T>
        void addParameter(ParameterPair & pp, bool optional = false);

        void addParameter(ParameterBase & paramBase, std::string name,
                          bool optional = false);

        void readFile(const std::string fileName);
};

#endif //PARAMETER_LIST_H
