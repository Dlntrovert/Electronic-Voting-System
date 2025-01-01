#include <iostream>
#include <vector>
#include <string>
#include "voter.h"
#include "candidate.h"
#include "admin.h"
#include <fstream>

using namespace std;

vector< pair<string, string> > admin_info = {{"Ezharul Islam", "Professor_JU"}, {"Masum Bhuiyan", "Lecturer_JU"}};

bool admin_login()
{
    admin a;
    a.get_info();
    for(int i=0; i<admin_info.size(); i++)
    {
        if(a.compare(admin_info[i].first, admin_info[i].second))
        {
            cout << endl << "Access granted.\n";
            return true;
        }
    }

    cout << endl << "Access denied.\n";
    return false;
}

int main()
{
    vector<candidate> candidate_list;
    vector<voter> voter_list;

    ifstream candidateFile("candidates.txt");
    if (candidateFile.is_open())
    {
        candidate::load_from_file(candidateFile, candidate_list);
        candidateFile.close();
    }

    ifstream voterFile("voters.txt");
    if (voterFile.is_open())
    {
        voter::load_from_file(voterFile, voter_list);
        voterFile.close();
    }

    while (true)
    {
        cout << "What would you like to do?\n";
        cout << "1. Register as a voter\n";
        cout << "2. Cast a vote\n";
        cout << "3. View candidates\n";
        cout << "4. Admin Login\n";
        cout << "5. Exit\n";

        int choice;
        cout << endl << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            voter v;
            v.get_register_info();
            voter_list.push_back(v);
            cout << endl;
        }
        else if (choice == 2)
        {
            if (candidate_list.empty())
            {
                cout << "No candidates available. Please try again later.\n" << endl;
                continue;
            }

            voter v;
            v.get_info();
            bool ok=true;
            for(int i=0; i<voter_list.size(); i++)
            {
                if(v==(voter_list[i]))
                {
                    voter_list[i].increa();

                    if(voter_list[i].isvoted()==1)
                    {
                        v.cast_vote(candidate_list);
                        voter_list[i].cast(v);
                        ok = false;
                        break;
                    }

                    else 
                    {
                        cout << "You already voted once. Can't vote again." << endl << endl;
                        ok = false;
                        break;
                    }   
                }
            }

            if(ok)
            {
                cout << "Voter not registered or entered name or ID does not match the registered name or ID." << endl;
            }

            cout << endl;
        }
        else if (choice == 3)
        {
            if (candidate_list.empty())
            {
                cout << "No candidates available.\n" << endl;
            }
            else
            {
                for (size_t i = 0; i < candidate_list.size(); ++i)
                {
                    cout << "Candidate No. " << (i+1) << ':' << endl;
                    candidate_list[i].show_info();
                    cout << endl;
                }
            }
        }
        else if (choice == 4)
        {
            if (admin_login())
            {
                while (true)
                {
                    cout << "\nAdmin Menu:\n";
                    cout << "1. Register a new candidate\n";
                    cout << "2. View voter list\n";
                    cout << "3. Back to main menu\n";

                    int admin_choice;
                    cout << endl << "Enter your choice, Admin: ";
                    cin >> admin_choice;

                    if (admin_choice == 1)
                    {
                        candidate c;
                        cout << endl << "Enter candidate information: " << endl;
                        c.get_info();
                        candidate_list.push_back(c);
                        cout << "Candidate registered successfully." << endl;
                    }
                    else if (admin_choice == 2)
                    {
                        if (voter_list.empty())
                        {
                            cout << "No voters registered yet.\n";
                        }
                        
                        else
                        {
                            cout << "Voter List:\n";
                            cout << "Voted == 1 means voter has already cast a vote. Voted == 0 means voter did not cast a vote yet." <<endl;
                            for (size_t i = 0; i < voter_list.size(); ++i)
                            {
                                cout << "Voter No. " << (i+1) << endl;
                                voter_list[i].show_info();
                            }
                        }
                    }
                    else if (admin_choice == 3)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Invalid choice. Try again." << endl << endl;
                    }
                }
            }
        }
        else if (choice == 5)
        {

            ofstream candidateOutFile("candidates.txt");
            if (candidateOutFile.is_open())
            {
                for (size_t i = 0; i < candidate_list.size(); ++i)
                {
                    candidate_list[i].save_to_file(candidateOutFile);
                }
                candidateOutFile.close();
            }

            ofstream voterOutFile("voters.txt");
            if (voterOutFile.is_open())
            {
                for(int i=0; i<voter_list.size(); i++)
                {
                    voter_list[i].save_to_file(voterOutFile);
                }
                voterOutFile.close();
            }

            vector<candidate>winner_list;
            candidate temp;

            for(int i=0; i<candidate_list.size(); i++)
            {
                if(candidate_list[i]>temp) 
                {
                    temp = candidate_list[i];
                }
            }

            for(int i=0; i<candidate_list.size(); i++)
            {
                if(candidate_list[i]==temp) 
                {
                    winner_list.push_back(candidate_list[i]);
                }
            }

            if(winner_list.size()==1)
            {
                cout<<"Ladies and Gentlemen. Your winner is: " <<endl;
                temp.show_info();
            }

            else cout<<"There are multiple winners. So, the vote is not decided." <<endl;
            cout << "Exiting program.\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again.\n" << endl;
        }
    }

    return 0;
}