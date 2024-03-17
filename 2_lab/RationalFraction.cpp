#include "RationalFraction.h"


RationalFraction::RationalFraction() {
	this->numerator = 0;
	this->denominator = 1;
}

RationalFraction::RationalFraction(int numerator) {
	this->numerator = numerator;
	this->denominator = 1;
}

RationalFraction::RationalFraction(int numerator, int denominator) {
	this->numerator = numerator;
	this->denominator = denominator;
}


bool RationalFraction::operator==(const RationalFraction& right) const {
	if (this->numerator == right.numerator 
		and this->denominator == right.denominator)
		return true;
	return false;
}

bool RationalFraction::operator>(const RationalFraction& right) const {
	// return false if one of them is Infinity
	if (this->denominator == 0 or right.denominator == 0) return false;
	double leftValue = this->numerator / double(this->denominator);
	double rightValue = right.numerator / double(right.denominator);
	return leftValue > rightValue;
}

RationalFraction RationalFraction::operator+() const {
	return *this;
}

RationalFraction RationalFraction::operator-() const {
	return RationalFraction(this->numerator * (-1), this->denominator);
}

RationalFraction& RationalFraction::operator++() { // prefix
	this->numerator = this->numerator + this->denominator;
	return *this;
}

RationalFraction RationalFraction::operator++(int v) { // postfix
	RationalFraction newFraction(this->numerator, this->denominator);
	this->numerator = this->numerator + this->denominator;
	return newFraction;
}

void RationalFraction::operator=(const RationalFraction& right) {
	this->numerator = right.numerator;
	this->denominator = right.denominator;
}

RationalFraction RationalFraction::operator-(const RationalFraction& right) const {
	int newNumerator = this->numerator * right.denominator - right.numerator * this->denominator;
	int newDenominator = this->denominator * right.denominator;
	RationalFraction newFraction(newNumerator, newDenominator);
	return newFraction;
}

RationalFraction RationalFraction::operator+(const RationalFraction& right) const {
	int newNumerator = this->numerator * right.denominator + right.numerator * this->denominator;
	int newDenominator = this->denominator * right.denominator;
	RationalFraction newFraction(newNumerator, newDenominator);
	return newFraction;
}

RationalFraction& RationalFraction::operator+=(const RationalFraction& right) {
	this->numerator = this->numerator * right.denominator + right.numerator * this->denominator;
	this->denominator = this->denominator * right.denominator;
	return *this;
}

RationalFraction& RationalFraction::operator-=(const RationalFraction& right) {
	this->numerator = this->numerator * right.denominator - right.numerator * this->denominator;
	this->denominator = this->denominator * right.denominator;
	return *this;
}


ostream& operator<<(ostream& os, const RationalFraction& f) {
	os << f.numerator << "/" << f.denominator;
	return os;
}

istream& operator>>(istream& is, RationalFraction& f) {
	static const regex reFraction(R"(^[+-]?[0-9]+(\/[0-9]+)?)");
	static const regex reInt(R"(^[+-]?[0-9]+)");
	std::smatch match;
	string input;
	is >> input;
	if (input.length() == 0) return is;
	else if (regex_match(input, match, reInt)) {
		f.numerator = std::stoi(input);
		f.denominator = 1;
		return is;
	}
	else if (regex_match(input, match, reFraction)) {
		string numeratorStr = input.substr(0, input.find('/'));
		string denominatorStr = input.substr(input.find('/') + 1, input.length());
		f.numerator = std::stoi(numeratorStr);
		f.denominator = std::stoi(denominatorStr);
		return is;
	}


}