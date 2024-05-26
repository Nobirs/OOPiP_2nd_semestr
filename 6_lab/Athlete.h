#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using std::string;
using std::ostream;

class Athlete
{
private:
    string name;
    int age;
    string country;
public:
    Athlete() : name("default"), age(18), country("Nigeria") {}
    Athlete(string name, int age, string country) : name(name), age(age), country(country) {}
    Athlete(const Athlete& obj) : name(obj.name), age(obj.age), country(obj.country) {}
    ~Athlete() {}

    // Getters
    string getName() { return name; }
    int getAge() { return age; }
    string getCountry() { return country; }

    // Setters
    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setCountry(string country) { this->country = country; }

    friend ostream& operator<<(ostream& out, const Athlete& obj);
};


ostream& operator<<(ostream& out, const Athlete& obj) {
    out << std::left << std::setw(20) << obj.name
        << std::setw(10) << obj.age
        << std::setw(10) << obj.country << std::endl;
    return out;
}