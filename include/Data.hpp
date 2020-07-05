#ifndef DATA_HPP
#define DATA_HPP
#include <vector>
#include <string>


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

    ~Datafield();

    void StoreField(std::ifstream &);
    void RestoreField(std::ofstream &);

private:
    char *pName;
    void *pValue;
    enum type_enum {char_pt, int_t, float_t} type;

    const unsigned int fieldNameSize = 100;
    const unsigned int strSize = 100;
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
    Datafield stfield {"name", "nullptr"};
    std::vector<Datafield> field;
    //---------------------------
    //---------------------------
    DataObject()
    {
        field.push_back(stfield);
        field.push_back(stfield);
        field.push_back(stfield);
        field.push_back(stfield);
        field.push_back(stfield);

        //field[2].erase(3);
    }

    void StoreObject(std::ifstream &);
    void RestoreObject(std::ofstream &);

    int size;   //quantity of fields in object
    char *name; //object name

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

    void StoreData(std::string filename= "save.txt");
    void RestoreData(std::string filename= "save.txt");
private:
    int size;       //quantity of objects in data
};

#endif // DATA_HPP
