//#include <iostream>
#include <conio.h>
#include <string>
#include <vector>

#include "Data.cpp"


int main()
{
    DataClass data;


/*
    data.object[0].field[0] = "CMake\0";
    data.object[0].field[0].print('\r');

    data.object[0].field[1] = 126;
    data.object[0].field[1].print('\r');

    data.object[0].field[2] = float(89.7);
    data.object[0].field[2].print('\r');
*/
    /*
    std::vector<int> vec;
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    std::vector<int>::iterator iter;
    iter = vec.begin();

    vec.insert(iter, 2);

    vec.erase(1);
    */


//---------------------------------------open file for restore
    std::ofstream fin("save.txt");


    fin.close();



//---------------------------------------programm_loop
    std::string str;
    std::string screen_str;

    std::string str_create  = "create";
    std::string str_delete  = "delete";
    std::string str_minus_o = "-o";
    std::string str_minus_f = "-f";
    std::string str_field   = "field";
    std::string str_done    = "done";

    bool create_m = false;
    bool delete_m = false;

    bool minus_o_m = false;
    bool minus_f_m = false;

    bool command = false;
    char key = 0;    //bufer for input symbol

    while(1)
    {
        //---------------------------draw window
        //std::cout << str << std::endl;
        //std::cout << screen_str;

        //---------------------------get input command
    //general commands
        if(str == str_create)
        {
            std::cout << "\n\tUsed command create" << std::endl;
            create_m = true;
            //-----
            screen_str += ' ';
            command = true;
            str = "";
        }

        else if(str == str_delete)
        {
            std::cout << "\n\tUsed command delete" << std::endl;
            delete_m = true;
            //-----
            screen_str += ' ';
            command = true;
            str = "";
        }


    //keys for commands
        if(str == str_minus_o)
        {
            std::cout << "\n\tUsed key minus o" << std::endl;
            minus_o_m = true;
            //-----
            screen_str += ' ';
            command = true;
            str = "";
        }

        else if(str == str_minus_f)
        {
            std::cout << "\n\tUsed key minus f" << std::endl;
            minus_f_m = true;
            //-----
            screen_str += ' ';
            command = true;
            str = "";
        }


        //sub commands
        if(str == str_field)
        {
            std::cout << "\n\tUsed sub command field" << std::endl;
            //-----
            screen_str += ' ';
            command = true;
            str = "";
        }
        if(str == str_done)
        {
            std::cout << "\n\tUsed sub command done" << std::endl;
            //-----
            screen_str += ' ';
            command = true;
            str = "";
        }

        //---------------------------action
        /*
        * create_m
        * delete_m
        * minus_o_m
        * minus_f_m
        */
        //Если create и -o тогда метод: data.object.push_back(stobject)
        //Если create и -f тогда метод: data.object[curobject()].push_back(stfield)

        //Если delete и -o тогда метод: data.object[curobject()].clear()
        //Если delete и -f тогда метод: data.object[curobject()].field[curfield()].


        //---------------------------user input
        key = 0;

        if(command)
        {
            while(char ch = getch() != ' ');
            command = false;
            system("cls");
        }
        else
        {
            key = getche();

            //virtual window
            str += key;
            screen_str += key;

            //clear virtual window
            if(key == '\r')
            {
                screen_str = "";
                str = "";
            }
        }
        //---------------------------
    }




    system("pause");
    return 0;
}
