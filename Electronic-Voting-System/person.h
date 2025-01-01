#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class person {
    protected:
        string name;

    public:
        person();
        void get_info();
        void show_info();
        bool operator == (person);
};

#endif
