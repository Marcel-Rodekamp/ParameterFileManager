//
// Created by Marcel Rodekamp on 25. Aug, 2019
// email: marcel.rodekamp@gmail.com
//
#ifndef PARAMETER_H
#define PARAMETER_H


#include <vector>

#include "../ParameterBase/parameterBase.h"
#include "../ParameterList/parameterList.h"

bool testParameter(bool printFlag);

template <class T>
class Parameter : public ParameterBase{
    private:
        std::vector<T> _values;

        friend class ParameterList;

        bool readstream(std::stringstream & sStream);

    public:
        Parameter(std::string & newName, bool optional, size_t size) :
            ParameterBase(newName, optional),
            _values(size) {}

        Parameter() : ParameterBase(), _values(1) {}

        size_t numberOfValues();

        const T& operator[](int index) const;

        T& operator()(int index = 0);
};

#endif // PARAMETER_H
