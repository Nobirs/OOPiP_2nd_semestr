#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Competition.h"
#include "Athlete.h"

using std::vector;
using std::string;
using std::ostream;


class Tournament {
private:
    string name;
    vector<Competition<int>*> competitions;
public:
    Tournament() : name("Default Tournament") {}
    Tournament(const string& name) : name(name) {}
    Tournament(const Tournament& t) : name(t.name), competitions(t.competitions) {}
    ~Tournament() { competitions.clear(); }

    // Getters
    string getName() { return name; }
    vector<Competition<int>*> getCompetitions() { return competitions; }

    // Setters
    void setName(string name) { this->name = name; }
    void setCompetitions(vector<Competition<int>*> cmps) { this->competitions = cmps; }

    void addCompetition(Competition<int>* cmp) { this->competitions.push_back(cmp); }


    friend ostream& operator<<(ostream& out, const Tournament& t);
};


ostream& operator<<(ostream& out, const Tournament& t) {
    out << std::left << std::setw(20) << t.name << std::endl;
    out << std::left << std::setw(10) << "Competitions: " << std::endl;
    for (Competition<int>* p : t.competitions)
    {
        out << std::left << std::setw(50) << *p;
    }
    return out;
}