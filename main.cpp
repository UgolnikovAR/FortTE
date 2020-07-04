//#include <iostream>
#include <conio.h>
#include <string>

#include "Data.cpp"


int main()
{
    DataClass data;



    data.object[0].field[0] = "CMake\0";
    data.object[0].field[0].print('\r');
/*
    data.object[0].field[1] = 126;
    data.object[0].field[1].print('\r');

    data.object[0].field[2] = float(89.7);
    data.object[0].field[2].print('\r');
*/


//programm_loop----------------------------------
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

    bool command = false;
    char key = 0;    //bufer for input symbol

    while(1)
    {
        //---------------------------clear screen
        system("cls");
        //std::cout << std::endl;
        //std::cout << std::endl;

        //---------------------------draw window
        std::cout << str << std::endl;
        std::cout << screen_str;

    //general commands
        if(str == str_create)
        {
            std::cout << "\n\tHello create" << std::endl;
            //-----
            screen_str += ' ';
            command = true;
            str = "";
        }

        else if(str == str_delete)
        {
            std::cout << "\n\tHello delete" << std::endl;
            //-----
            screen_str += ' ';
            command = true;
            str = "";
        }

     //sub commands
        if(str == str_field)
        {
            std::cout << "\n\tHello field" << std::endl;
            //-----
            screen_str += ' ';
            command = true;
            str = "";
        }
        if(str == str_done)
        {
            std::cout << "\n\tHello done" << std::endl;
            //-----
            screen_str += ' ';
            command = true;
            str = "";
        }

    //keys for commands
        if(str == str_minus_o)
        {
            std::cout << "\n\tHello minus o" << std::endl;
            if(create_m)
            {

            }
            //-----
            screen_str += ' ';
            command = true;
            str = "";

        }

        else if(str == str_minus_f)
        {
            std::cout << "\n\tHello minus f" << std::endl;
            //-----
            screen_str += ' ';
            command = true;
            str = "";

        }



        //---------------------------user input
        key = 0;

        if(command)
        {
            while(char ch = getch() != ' ');
            command = false;
        }
        else
        {

            key = getch();


            str += key;
            screen_str += key;


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
