#ifndef VOTER_H
#define VOTER_H

#include "person.h"
#include <string>
#include <vector>
#include "candidate.h"

using namespace std;

class voter : public person {
private:
    long long int voter_id;
    string cast_vote_to;
    int voted;

public:
    voter();
    void get_info();
    void get_register_info();
    void show_info();
    void cast_vote(vector<candidate>& candidate_list);
    bool operator==(voter temp);
    bool isvoted();
    void increa();
    void cast(voter v);
    static void load_from_file(std::ifstream& inFile, vector<voter>& voter_list);
    void save_to_file(ofstream& outFile);
};

#endif
