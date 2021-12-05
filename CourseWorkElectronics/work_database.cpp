#include "work_database.h"

void work_database::filled(string str)
{
    string smth;
    string copys;
    ifstream out;
    out.open("test.txt",ios_base::binary);
    while (getline(out, smth))
    {
            copys += smth;
            copys.push_back('\n');
    }
    out.close();
    remove("test.txt");
    output.open(str,ios_base::binary); // Для добавляения файла ниже | ios_base::app;
    output << copys;
    output.close();
}
