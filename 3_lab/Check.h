#pragma once
#include <string>
#include <iostream>


#include "Product.h"
#include "CurrentTime.h"


using std::string;
using std::ostream;


class Check
{
private:
	Product *p;
	string productName;
	double price;
	uint32_t count;
	double overallPrice;
protected:
	string date;
	string time;

public:
	// Constructors
	Check();
	Check(const Product& p, const uint32_t c, string date, string time);

	// Destructor
	~Check();

	// Getters
	string getProductName() const { return this->productName; }
	double getPrice() const { return this->price; }
	uint32_t getCount() const { return this->count; }
	double getOverallPrice() const { return this->overallPrice; }
	string getDate() const { return this->date; }
	string getTime() const { return this->time; }

	// Setters
	void setProductName(const string& name);
	void setPrice(const double& price);
	void setCount(const uint32_t& count);
	void setOverallPrice(const double& price);
	void setDate(const string& date);
	void setTime(const string& time);

	// Useful methods
	double calcOverallPrice();

	ostream& operator<<(ostream& os) {
		os << productName << " ";
		os << count << " ";
		os << overallPrice << std::endl;
		return os;
	}
};

