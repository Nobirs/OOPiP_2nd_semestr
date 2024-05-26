#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "Athlete.h"

using std::string;
using std::vector;
using std::ostream;


class Event {
private:
    string name;
    string location;
    string dateTime;
    vector<Athlete> participants;
public:
    Event() : name("Default event"), location("USA"), dateTime("20.01.2025") {}
    Event(const string& name, const string& location, const string& dateTime)
        : name(name), location(location), dateTime(dateTime) {}
    Event(const Event& obj) : name(obj.name), location(obj.location), dateTime(obj.dateTime) {}
    ~Event() { participants.clear(); }

    // Getters
    string getName() { return name; }
    string getLocation() { return location; }
    string getDateTime() { return dateTime; }
    vector<Athlete> getParticipants() { return participants; }

    // Setters
    void setName(string name) { this->name = name; }
    void setLocation(string location) { this->location = location; }
    void setDateTime(string dt) { this->dateTime = dt; }
    void setParticipants(vector<Athlete> p) { this->participants = p; }

    void addAthlete(Athlete a) { this->participants.push_back(a); }

    friend ostream& operator<<(ostream& out, const Event& e);

};


ostream& operator<<(ostream& out, const Event& e) {
    out << std::left << std::setw(20) << e.name
        << std::setw(15) << e.location
        << std::setw(10) << e.dateTime << std::endl;
    out << "Participants: " << std::endl;
    for (auto p : e.participants) {
        out << "  " << p;
    }
    return out;
}