#include <iostream>
class DataElement
{
public:
    void print(char param='\0');
    //-----------------------------------
    void operator = (char* char_var);
    void operator = (int int_var);
    void operator = (float float_var);
    //------------------------------------
    DataElement(char* char_var) : pElement(char_var){}
    DataElement(int int_var);
    DataElement(float float_var);

private:
    void* pElement;
    enum type_enum {char_pt, int_t, float_t} type;
};

//constructor
DataElement::DataElement(int int_var)
{
    pElement = new int;
    int *tmp = reinterpret_cast<int*>(pElement);
    *tmp = int_var;
}

DataElement::DataElement(float float_var)
{
    pElement = new float;
    float *tmp = reinterpret_cast<float*>(pElement);
    *tmp = float_var;
}


void DataElement::operator = (char* char_var) {
    type = char_pt;
    pElement = char_var;
}

void DataElement::operator = (int int_var)
{
    type = int_t;
    pElement = new int;
    int *tmp = reinterpret_cast<int*>(pElement);
    *tmp = int_var;
}

void DataElement::operator = (float float_var)
{
    type = float_t;
    pElement = new float;
    float *tmp = reinterpret_cast<float*>(pElement);
    *tmp = float_var;
}



void DataElement::print(char param)
{
    switch(type)
    {
        case char_pt:
        {
            std::cout << reinterpret_cast<char*>(pElement);
            if(param == '\r') std::cout << std::endl;
            break;
        }
        case int_t:
        {
            std::cout << *(reinterpret_cast<int*>(pElement));
            if(param == '\r') std::cout << std::endl;
            break;
        }
        case float_t:
        {
            std::cout << *(reinterpret_cast<float*>(pElement));
            if(param == '\r') std::cout << std::endl;
            break;
        }
    }
}




class DataClass
{
public:
    /*
     *some pElements of data structure
    */
    DataElement element;

    DataClass();
private:
    /*
     *some methods:
         void StoreData()    -saving architect state of programm in "n_version.txt"
         void RestoreData()  -load architect state of programm from "n_version.txt"
    */
};

DataClass::DataClass():element(0){}


