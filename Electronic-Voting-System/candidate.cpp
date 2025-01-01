#include "candidate.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

candidate::candidate() : candidate_id(0), votes(0), age(0) {}

string candidate::get_symbol() const {
    return symbol;
}

void candidate::increment_votes() {
    votes++;
}

void candidate::get_info() 
{
    cout << "Enter candidate name: ";
    person::get_info();  
    cout << "Enter candidate id: ";
    cin >> candidate_id;
    cout << "Enter party name: ";
    cin >> party_name;
    cout << "Enter candidate symbol: ";
    cin >> symbol;
    cout << "Enter candidate age: ";
    cin >> age;    
}
     

bool candidate::age_varify()
{
    if (age >= 21)
        return true;
    else
        return false;
}


bool candidate::operator==(candidate a)
{
    if(votes == a.votes) return true;
    else return false;
}

bool candidate::operator>(candidate a)
{
    return (votes > a.votes);
}

void candidate::show_info() {
    cout << "Candidate name: " << name << endl;
    cout << "Candidate ID: " << candidate_id << endl;
    cout << "Party: " << party_name << endl;
    cout << "Symbol: " << symbol << endl;
    cout << "Votes: " << votes << endl;
}

void candidate::save_to_file(std::ofstream& outFile) {
    outFile << name << '\n' << candidate_id << '\n' << party_name << '\n'
            << symbol << '\n' << votes << '\n' << age << '\n';
}

void candidate::load_from_file(std::ifstream& inFile, std::vector<candidate>& candidate_list) {
    
    //ifstream obj_file;
    //while (!obj_file.eof()) 
    //{
        candidate c;
        inFile >> c.name >> c.candidate_id >> c.party_name >> c.symbol >> c.votes >> c.age;
        candidate_list.push_back(c);
    //}
    
}
