#include <iostream>
#include <vector>
#include <fstream>
#include "Data.hpp"



//constructor
Datafield::Datafield(char* name, char* char_var)
{
    pName = new char[fieldNameSize];
    *pName = *name;

    pValue = new char[strSize];
    char *tmp = reinterpret_cast<char*>(pValue);
    *tmp = *char_var;
}

Datafield::Datafield(char* name, int int_var)
{
    pName = new char[fieldNameSize];
    *pName = *name;

    pValue = new int;
    int *tmp = reinterpret_cast<int*>(pValue);
    *tmp = int_var;
}

Datafield::Datafield(char* name, float float_var)
{
    pName = new char[fieldNameSize];
    *pName = *name;

    pValue = new float;
    float *tmp = reinterpret_cast<float*>(pValue);
    *tmp = float_var;
}

//destructor
Datafield::~Datafield()
{
    delete [] pName;
    char *tmp = reinterpret_cast<char*>(pValue);

    if(type == char_pt)             //delete str
    {
        delete [] tmp;
    }
    else if(type == int_t)          //delete int
    {
        int *tmp = reinterpret_cast<int*>(pValue);
        delete tmp;
    }
    else if(type == float_t)        //delete float
    {
        float *tmp = reinterpret_cast<float*>(pValue);
        delete tmp;
    }
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

void Datafield::StoreField(std::ifstream & fout)
{
    fout << pName;     //name of field

    switch(type)
    {
        case char_pt:
        {
            fout << reinterpret_cast<char*>(pValue);     //char value of field
            break;
        }
        case int_t:
        {
            int *tmp = reinterpret_cast<int*>(pValue);           //int value of field
            tmp = int_var;
            fout << *tmp;
            break;
        }

        case float_t:
        {
            int *tmp = reinterpret_cast<float*>(pValue);         //float value of field
            tmp = int_var;
            fout << *tmp;
            break;
        }
    }
}


//class DataObject
void DataObject::StoreObject(std::ifstream &fout)
{
}


//class DataClass
void DataClass::StoreData(std::string filename)
{
    using namespace std;
//open file for saving
    int it = 0;
    std::ifstream fout(filename, std::ios_base::out |
                                 std::ios_base::app |
                                 std::ios_base::binary);

    int curobject = size - it;
    int curfield  = object[curobject].size - it;
    fout.write((char*)(&object[curobject]), sizeof object[curobject]);                      //name of object
    fout.write(object[curobject].field.size(), 4);              //size of vector


    fout.close();
}
