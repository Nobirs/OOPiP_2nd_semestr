#pragma once
#include <string>

#include "Person.h"

using std::string;
using std::ostream;


class Employee {
public: // ������� ���-�� ������� ����� � �����
    static const int workHoursPerMonth = 168;
private:
    Person person;
    int workedHours; // ���-�� ������������ ����� � ������
    int workExperience; // ���� ������(� �����)
    double bonus; // ������
    double salary; // �����
    double hourlyWage; // ������� ���������� �����
    double salaryKoeff;
public:
    Employee();
    Employee(Person p, int workedHours, int workExperience, double hourlyWage);

    void setPerson(Person* p);
    void setWorkedHours(int value);
    void setWorkExperience(int value);
    void setBonus(double value);
    void setSalary(double value);
    void setHourlyWage(double value);

    Person getPerson() const { return this->person; }
    int getWorkedHours() const { return this->workedHours; }
    int getWorkExperience() const { return this->workExperience; }
    double getBonus() const { return this->bonus; }
    double getSalary() const { return this->salary; }
    double getHourlyWage() const { return this->hourlyWage; }
    double getSalaryKoeff() const { return this->salaryKoeff; }

    void updateSalary();
    void updateBonus();
};