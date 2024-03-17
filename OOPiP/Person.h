#pragma once

#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::endl;


class Person {
private:
    string firstName;
    string lastName;
    string fatherName;
public:
    Person()
    {
        firstName = "TestUser";
        lastName = "TestUser";
        fatherName = "TestUser";
    }

    Person(string firstName, string lastName, string fatherName = "")
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->fatherName = fatherName;
    }
    string getFirstName() const { return this->firstName; }
    string getLastName() const { return this->lastName; }
    string getFatherName() const { return this->fatherName; }
    void setFirstName(string firstName) {
        this->firstName = firstName;
    }

    void setLastName(string lastName) {
        this->lastName = lastName;
    }

    void setFatherName(string fatherName) {
        this->fatherName = fatherName;
    }
};
