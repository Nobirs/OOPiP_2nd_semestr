#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Athlete.h"

using std::string;
using std::vector;
using std::ostream;


class Team {
private:
    string name;
    string coach;
    vector<Athlete> players;
public:
    Team() : name("Default Team"), coach("Egor") {}
    Team(const string& name, const string& coach) : name(name), coach(coach) {}
    Team(const Team& obj) : name(obj.name), coach(obj.coach) {}
    ~Team() { players.clear(); }

    // Getters
    string getName() { return name; }
    string getCoach() { return coach; }
    vector<Athlete> getPlayers() { return players; }

    // Setters
    void setName(string name) { this->name = name; }
    void setCoach(string coach) { this->coach = coach; }
    void setPlayers(vector<Athlete> p) { this->players = p; }

    void addPlayer(Athlete a) { this->players.push_back(a); }


    friend ostream& operator<<(ostream& out,const Team& t);
};


ostream& operator<<(ostream& out, const Team& t) {
    out << std::left << std::setw(10) << "Team: " << std::endl;
    for (auto player : t.players)
    {
        out << std::setw(50) << player << std::endl;
    }
    return out;
}