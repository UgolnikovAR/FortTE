#include <iostream>
#include <vector>
#include "Data.hpp"


Datafield::Datafield(char* name, char* char_var)
{
    pName = name;
    pValue = char_var;
}

Datafield::Datafield(char* name, int int_var)
{
    pName = name;
    pValue = new int;
    int *tmp = reinterpret_cast<int*>(pValue);
    *tmp = int_var;
}

Datafield::Datafield(char* name, float float_var)
{
    pName = name;
    pValue = new float;
    float *tmp = reinterpret_cast<float*>(pValue);
    *tmp = float_var;
}


void Datafield::operator = (char* char_var)
{
    type = char_pt;
    pValue = char_var;
}

void Datafield::operator = (int int_var)
{
    type = int_t;
    pValue = new int;
    int *tmp = reinterpret_cast<int*>(pValue);
    *tmp = int_var;
}

void Datafield::operator = (float float_var)
{
    type = float_t;
    pValue = new float;
    float *tmp = reinterpret_cast<float*>(pValue);
    *tmp = float_var;
}


void Datafield::print(char param)
{
    switch(type)
    {
        case char_pt:
        {
            std::cout << reinterpret_cast<char*>(pValue);
            if(param == '\r') std::cout << std::endl;
            break;
        }
        case int_t:
        {
            std::cout << *(reinterpret_cast<int*>(pValue));
            if(param == '\r') std::cout << std::endl;
            break;
        }
        case float_t:
        {
            std::cout << *(reinterpret_cast<float*>(pValue));
            if(param == '\r') std::cout << std::endl;
            break;
        }
    }
}


//class DataObject


//class DataClass

