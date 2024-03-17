#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <string_view>
#include <Windows.h>


#include "Employee.h"


using namespace std;

#define DEFAULT_PROMPT ">>>"


int inputInt(string prompt, int from = INT_MIN, int to = INT_MAX, bool checkBetween = false) {
    static const regex re(R"(^-?[0-9]+)"s);
    while (true) {
        string input;
        smatch match;
        cout << prompt;
        cin.clear();
        getline(cin, input);
        string_view input_view(input);
        if (regex_match(input, match, re))
        {
            int value = stoi(input);
            if (!checkBetween) return value;
            if (checkBetween and (value >= from) and (value <= to)) return value;
        }
        cerr << "Incorrect input. Try again..." << endl;
    }
}


double inputDouble(string prompt) {
    static const regex re(R"(^[+-]?[0-9]*\.?[0-9]+)"s);
    while (true) {
        string input;
        smatch match;
        cout << prompt;
        cin.clear();
        getline(cin, input);
        string_view input_view(input);
        if (regex_match(input, match, re))
        {
            double value = stod(input);
            return value;
        }
        cerr << "Incorrect input. Try again..." << endl;
    }
}


char inputYesNo(string prompt) {
    static const regex re(R"([y|n])"s);
    while (true) {
        string input;
        smatch match;
        cout << prompt;
        cin.clear();
        getline(cin, input);
        string_view input_view(input);
        if (regex_match(input, match, re))
        {
            return input[0];
        }
        else
        {
            cerr << "Incorrect input. Try again..." << endl;
        }
    }
}


ostream& operator<<(ostream& os, const Person& p)
{
    os << "FirstName: " << p.getFirstName() << std::endl;
    os << "LastName: " << p.getLastName() << std::endl;
    os << "FatherName: " << p.getFatherName() << std::endl;
    return os;
}


ostream& operator<<(ostream& os, const Employee& e)
{

    os << e.getPerson() << std::endl;
    os << "Worked Hours: " << e.getWorkedHours() << std::endl;
    os << "Work Experience: " << e.getWorkExperience() << std::endl;
    os << "Bonus: " << e.getBonus() << std::endl;
    os << "Salary: " << e.getSalary() << std::endl;
    os << "Hourly Wage: " << e.getHourlyWage() << std::endl;
    os << "Salary Koeff: " << e.getSalaryKoeff() << std::endl;
    return os;
}


void printEmployee(Employee* e) {
    cout << "------------------------------------------" << endl;
    cout << *e;
    cout << "------------------------------------------" << endl;
}


Person* inputPersonData() {
    string firstName;
    string lastName;
    string fatherName;

    cin.clear();
    cout << "firstName: ";
    getline(cin, firstName);
    cout << "lastName: ";
    getline(cin, lastName);
    cout << "fatherName: ";
    getline(cin, fatherName);

    Person* p = new Person(firstName, lastName, fatherName);
    return p;
}


Employee* inputNewEmployee() {
    Employee* e;

    Person *p = inputPersonData();
    int workedHours = inputInt("Worked Hours: ");
    int workExperience = inputInt("Work Experience: ");
    double hourlyWage = inputDouble("Hourly Wage: ");

    e = new Employee(*p, workedHours, workExperience, hourlyWage);

    return e;
}


int main(int argc, char** argv) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Employee*> vec;
    while (true) {
        cout << "New employee: " << endl;
        vec.push_back(inputNewEmployee());

        char answer = inputYesNo("Continue[y/n]? ");
        if (answer == 'n') break;
        cout << endl;
    }
    for (auto e : vec) {
        printEmployee(e);
    }



    return 0;
}