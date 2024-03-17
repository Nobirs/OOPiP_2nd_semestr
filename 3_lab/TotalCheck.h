#pragma once
#include <iostream>
#include <vector>
#include "Check.h"

#define BREAK_LINE "---------------------------------------------\n"

using std::vector;
using std::ostream;

class TotalCheck : public Check
{
private:
	vector<Check*> allChecks;
	double endPrice;

public:
	TotalCheck();
	~TotalCheck();

	// getters
	vector<Check*>* getChecks() { return &allChecks; }
	double getEndPrice() { return endPrice; }

	// setters
	void setChecks(vector<Check*> c) {} // DO NOTHING! USE addCheck instead!!!
	void setPrice() {} // DO NOTHING! USE calcPrice instead!!!

	// Useful methods
	void addCheck(Check* ch);
	void calcPrice();
	void updateDateAndTime();

	// operators
	friend ostream& operator<<(ostream& os, const TotalCheck& ch);
};

