#include "admin.h"
#include "voter.h"
#include "candidate.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

admin::admin() : admin_name(""), password("") {}

void admin::get_info() {
    cout << "Enter admin name: ";
    cin.ignore();
    getline(cin, admin_name);
    cout << "Enter password(No spaces allowed): ";
    cin >> password;
}

bool admin::compare(string a, string s) {
    return (admin_name == a && password == s);
}