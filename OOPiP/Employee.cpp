#include "Employee.h"


Employee::Employee() {
    workedHours = 0;
    workExperience = 0;
    bonus = 0;
    salary = 250.0;
    hourlyWage = salary / 168;
    salaryKoeff = workedHours / double(workHoursPerMonth);
}

Employee::Employee(Person p, int workedHours, int workExperience, double hourlyWage) {
    {
        this->person = p;
        this->workedHours = workedHours;
        this->workExperience = workExperience;
        this->hourlyWage = hourlyWage;
        this->salaryKoeff = this->workedHours / double(this->workHoursPerMonth);
        updateSalary(); // Calculate current salary(via workedHours in this month)
        updateBonus(); // Calcuate current bonus(via workExperience);
    }
}

void Employee::setPerson(Person* p) {
    this->person = *p;
}

void Employee::setWorkedHours(int value) {
    this->workedHours = value;
    updateSalary();
    updateBonus();
}

void Employee::setWorkExperience(int value) {
    this->workExperience = value;
    updateSalary();
    updateBonus();
}

void Employee::setBonus(double value) {
    this->bonus = value;
}

void Employee::setSalary(double value) {
    this->salary = value;
}

void Employee::setHourlyWage(double value) {
    this->hourlyWage = value;
    updateSalary();
    updateBonus();
}


void Employee::updateSalary() {
    this->salary = this->workedHours * this->hourlyWage;
}


void Employee::updateBonus() {
    if (this->workExperience < 1) {
        this->bonus = this->salary * 0.01;
    }
    else if (this->workExperience < 3) {
        this->bonus = this->salary * 0.05;
    }
    else if (this->workExperience < 5) {
        this->bonus = this->salary * 0.08;
    }
    else if (this->workExperience >= 5) {
        this->bonus = this->salary * 0.15;
    }
}