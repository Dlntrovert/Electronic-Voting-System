#include "voter.h"
#include <iostream>
#include <fstream>

using namespace std;

voter::voter() : voter_id(0), cast_vote_to("") {}

void voter::get_info() {
    cout << "Enter voter name: ";
    person::get_info();
    fflush(stdin);
    cout << "Enter voter ID: ";
    long long int a;
    cin >> voter_id;
    cout << "Cast your vote to: ";
    cin >> cast_vote_to;
}

void voter::increa()
{
    voted++;
}

void voter::get_register_info()
{
    cout << "Enter voter name: ";
    person::get_info();
    fflush(stdin);
    cout << "Enter voter ID: ";
    cin >> voter_id;
    voted = 0;
    cast_vote_to = "";
}

void voter::cast(voter v)
{
    cast_vote_to = v.cast_vote_to;
}

void voter::show_info() {
    cout << "Voter Name: " << name << ", ID: " << voter_id << ", Voted for: " << cast_vote_to << " , voted? " << voted <<endl;
}

bool voter::operator==(voter temp) {
    return (voter_id == temp.voter_id && person::operator==(temp));
}

void voter::cast_vote(std::vector<candidate>& candidate_list) {
    bool found = false;
    for (int i = 0; i < candidate_list.size(); i++) {
        if (candidate_list[i].get_symbol() == cast_vote_to) {
            candidate_list[i].increment_votes();
            cout << "Vote for " << cast_vote_to << " has been successfully cast.\n";
            found = true;
            break; 
        }
    }
    if (!found) {
        cout << "Invalid candidate symbol. Vote not cast.\n";
    }
}


bool voter:: isvoted()
{
    if(voted == 1) return true;
    else return false;
}

void voter::save_to_file(std::ofstream& outFile) {
    outFile << name << '\n' << voter_id << '\n' << cast_vote_to << '\n'
            << voted << '\n';
}

void voter::load_from_file(std::ifstream& inFile, std::vector<voter>& voter_list) {
    voter v;
    inFile >> v.name >> v.voter_id >> v.cast_vote_to >>  v.voted;
    voter_list.push_back(v);
}