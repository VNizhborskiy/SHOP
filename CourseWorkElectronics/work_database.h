#ifndef WORK_DATABASE_H
#define WORK_DATABASE_H
#include <iostream>
#include <fstream>
using namespace std;
class work_database
{
public:
    void filled(string str);
private:
    ofstream output;
    ifstream input;
};

#endif // WORK_DATABASE_H
