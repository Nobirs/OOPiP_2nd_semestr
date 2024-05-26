#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <tuple>

#include "Athlete.h"

using std::string;
using std::vector;
using std::ostream;
using std::tuple;
using std::get;


template<typename T>
class Competition {
private:
    string type;
    vector<tuple<Athlete, T>> participants;
public:
    Competition() : type("Run(100m)") {}
    Competition(const string& type) : type(type) {}
    Competition(const Competition& cmp) : type(cmp.type) {}
    ~Competition() { participants.clear(); }

    // Getters
    string getType() { return type; }
    vector<tuple<Athlete, T>> getParticipants() { return participants; }

    // Setters
    void setType(string type) { this->type = type; }
    void setParticipants(vector<tuple<Athlete, T>> p) { this->participants = p; }

    void addParticipant(tuple<Athlete, T> p) { this->participants.push_back(p); }

    friend ostream& operator<<(ostream& out, const Competition<int>& cmp);
};


ostream& operator<<(ostream& out, const Competition<int>& cmp) {
    out << std::left << std::setw(20) << "Results:" << std::endl;
    for (auto tpl : cmp.participants) {
        out << std::setw(10) << get<int>(tpl)
            << std::setw(50) << get<Athlete>(tpl) << std::endl;
    }
    return out;
}