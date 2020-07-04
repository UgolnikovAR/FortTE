#ifndef DATA_HPP
#define DATA_HPP
#include <vector>


/*
 * Datafield class
 *
 * this class is universal cell,
 * that may point any data objects.
*/
class Datafield
{
public:
    void print(char param='\0');
    //-----------------------------------
    void operator = (char* char_var);
    void operator = (int int_var);
    void operator = (float float_var);
    //------------------------------------
    Datafield(char* name, char* char_var);
    Datafield(char* name, int int_var);
    Datafield(char* name, float float_var);

private:
    char *pName;
    void *pValue;
    enum type_enum {char_pt, int_t, float_t} type;
};


/*
 * DataObject class
 *
 * this class is dynamic container
 * for Datafield's.
*/
class DataObject
{
public:
    Datafield input {"name", "nullptr"};
    std::vector<Datafield> field;
    //---------------------------
    //---------------------------
    DataObject()
    {
        field.push_back(input);
    }


private:

};


/*
 * DataClass class
 *
 * this class is dynamic container
 * for DataObject's.
*/
class DataClass
{
public:
    DataObject inputObject;
    std::vector<DataObject> object;
    //-----------------------------------

    DataClass()
    {
        object.push_back(inputObject);
    }
private:
    /*
     *some methods:
         void StoreData()    -saving architect state of programm in "n_version.txt"
         void RestoreData()  -load architect state of programm from "n_version.txt"
    */
};

#endif // DATA_HPP
