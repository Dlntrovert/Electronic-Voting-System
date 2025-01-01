#ifndef CANDIDATE_H
#define CANDIDATE_H

#include "person.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class candidate : public person {
private:
    long long int candidate_id;
    string party_name;
    string symbol;
    unsigned int votes;
    unsigned int age;

public:
    candidate();
    
    string get_symbol() const;
    void increment_votes();
    void get_info();
    void show_info();
    bool age_varify();
    bool operator>(candidate a);
    void save_to_file(ofstream& outFile);
    bool operator == (candidate a);
    string get_name() const { return name; } 
    
    static void load_from_file(std::ifstream& inFile, vector<candidate>& candidate_list);
};

#endif