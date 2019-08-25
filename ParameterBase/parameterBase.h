//
// Created by Marcel Rodekamp on 25. Aug, 2019
// email: marcel.rodekamp@gmail.com
//
#ifndef PARAMETER_BASE_H
#define PARAMETER_BASE_H

#include <string>
#include <iostream>

bool testParameterPair(bool printFlag = true);
bool testParameterBase(bool printFlag = true);

struct ParameterPair{
    /*
     * This struct is used for some initialization methods.
     * It presents a primitive dictionary of name and values of a new
     * parameter in string format.
     */
    std::string key;
    std::string val;

    ParameterPair(std::string & line){
        // Find delimitter in line
        size_t delimitter = line.find('=');

        // Return if no delimitter is found
        if (delimitter == std::string::npos) {
            return;
        }

        // Substrakt key and value
        key = line.substr(0,delimitter);
        val = line.substr(delimitter + 1);

        // erase white spaces
        key.erase( key.find_last_not_of( " \t\r\n\v\f"  ) + 1 );
    }

    std::string & getKey();
    std::string & getVal();

};

class ParameterBase{
    /*
     * This pure virtual class provides the minimal base of a parameter.
     */
    private:
        std::string _name;
        bool _isOptional;
        bool _isSet;

        virtual bool readstream(std::stringstream & sStream) = 0;

    public:
        ParameterBase(std::string & newName, bool optional) :
                    _name(newName),
                    _isOptional(optional),
                    _isSet(false)  {}
        ParameterBase() :
                    _isOptional(false),
                    _isSet(false) {}

        std::string & getName();

        void setName(const std::string & newName);

        bool isOptional();

        void setOptional(const bool newValue);

        bool isSet();

        void setSet(const bool newValue);

        bool initParam( ParameterPair & paramPair );

        bool cleanInitParam( std::string name);

        friend class ParameterList;
};

#endif // PARAMETER_BASE_H
