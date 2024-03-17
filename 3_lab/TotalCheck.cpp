#include "TotalCheck.h"

TotalCheck::TotalCheck() {
	endPrice = 0.0;
}

TotalCheck::~TotalCheck() {
	allChecks.clear();
}

void TotalCheck::addCheck(Check* ch)
{
	allChecks.push_back(ch);
	calcPrice();
	updateDateAndTime();
}

void TotalCheck::updateDateAndTime()
{
	this->date = getCurrLocalDate();
	this->time = getCurrLocalTime();
}

void TotalCheck::calcPrice()
{
	endPrice = 0.0;
	for (auto ch : allChecks) {
		endPrice += ch->getOverallPrice();
	}
	updateDateAndTime();
}

ostream& operator<<(ostream& os, const TotalCheck& ch)
{
	os << BREAK_LINE;
	for (auto check : ch.allChecks) {
		os << check->getProductName() << " ";
		os << check->getCount() << " ";
		os << check->getOverallPrice() << "$ ";
		os << std::endl;
	}
	os << "\n";
	os << "Total Price: " << ch.endPrice << " $" << std::endl;
	os << "Date: " << ch.getDate() << " Time: " << ch.getTime() << std::endl;
	os << BREAK_LINE;
	return os;
}
