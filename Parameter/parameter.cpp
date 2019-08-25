//
// Created by Marcel Rodekamp on 25. Aug, 2019
// email: marcel.rodekamp@gmail.com
//

#include <sstream>

#include "../ParameterBase/parameterBase.h"
#include "parameter.h"
#include "../ParameterList/parameterList.h"

/****************************************************************************************
*
* Function definitions of class Parameter
*
***************************************************************************************/

template <class T>
bool Parameter<T>::readstream(std::stringstream & sStream){
    // reset the Parameter
    _values.clear();

    this->setSet(false);

    do {
        // get the values from the stringStream into a temp variable
        T temp;

        sStream >> temp;

        if(sStream.fail()){break;}

        // push the values into the container
        _values.push_back( temp );
    }while(sStream.good());

    this->setSet(true);

    return this->isSet();
}

template <class T>
size_t Parameter<T>::numberOfValues(){
    return _values.size();
}

template <class T>
const T& Parameter<T>::operator[](int index) const {
    return _values[index];
}

template <class T>
T& Parameter<T>::operator()(int index) {
    return _values.at(index);
}

//Explicit instantation.
// TODO is there a way around?
template class Parameter<int>;
template class Parameter<float>;
template class Parameter<double>;
template class Parameter<std::string>;
