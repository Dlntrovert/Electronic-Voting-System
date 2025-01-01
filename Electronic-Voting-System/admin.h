#ifndef ADMIN_H
#define ADMIN_H

#include "person.h"
#include "voter.h"
#include "candidate.h"
#include <vector>

class admin : public person
{
private:
    string admin_name;
    string password;

public:
    admin();
    void get_info();
    bool compare(string a, string s);
};

#endif
