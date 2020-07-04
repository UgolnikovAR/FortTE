//#include <iostream>
#include <conio.h>
#include "DataClass.cpp"

int main()
{
    DataClass data;

    data.field = "Hello1\0";
    data.field.print('\r');

    data.field = 126;
    data.field.print('\r');

    data.field = float(89.7);
    data.field.print('\r');

    system("pause");
    return 0;
}


//ch = getch()
//system("cls");
