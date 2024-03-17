#pragma once
#include <iostream>
#include <string>
#include <string_view>
#include <regex>

using std::ostream;
using std::istream;
using std::string;
using std::regex;
using std::string_view;
using std::regex_match;

class RationalFraction
{
private:
	int numerator; // числитель
	int denominator; // знаменатель
public:
	RationalFraction(); // DONE
	RationalFraction(int numerator); // DONE
	RationalFraction(int numerator, int denominator); // DONE

	// overloading operators
	bool operator==(const RationalFraction& right) const; // DONE
	bool operator>(const RationalFraction& right) const; // DONE
	RationalFraction operator+() const; // DONE
	RationalFraction operator-() const; // DONE
	RationalFraction& operator++(); // prefix  // DONE
	RationalFraction operator++(int); // postfix // DONE
	void operator=(const RationalFraction& right); // DONE
	RationalFraction operator-(const RationalFraction& right) const; // DONE
	RationalFraction operator+(const RationalFraction& right) const; // DONE
	RationalFraction& operator+=(const RationalFraction& right); // DONE
	RationalFraction& operator-=(const RationalFraction& right); // DONE

	// friend functions
	friend ostream& operator<<(ostream& os, const RationalFraction& f); // DONE
	friend istream& operator>>(istream& is, RationalFraction& f); // DONE
};

