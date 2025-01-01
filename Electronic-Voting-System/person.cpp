#include "person.h"
#include <iostream>
#include <fstream>

using namespace std;

person::person()
{
    name = "";
}

void person::get_info()
{
    cin.ignore();
    getline(cin, name);
}

bool person::operator==(person a)
{
    return (name == a.name);
}

void person::show_info()
{
    cout << "Name: " << name << endl;
}

