#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::cout;
using std::endl;

class Product
{
protected:
	string name;
	double price;
	double discountPercent;

public:
	Product() {
		name = "default";
		price = 5.99;
		discountPercent = 0.5;
	}

	Product(string name, double price, double discount) {
		this->name = name;
		this->price = price;
		this->discountPercent = discount;
	}

	double getDiscountAmount() const {
		return price * discountPercent;
	}

	double getDiscountPrice() const {
		return price - price * discountPercent;
	}

	virtual void printDescription() {
		cout << "Product: " << endl;
		cout << "-------------------------------------" << endl;
		cout << "Name: " << this->name << endl;
		cout << "Price(No discount): " << this->price << endl;
		cout << "Discount Percent: " << this->discountPercent << endl;
		cout << "Discount amount: " << this->getDiscountAmount() << endl;
		cout << "End Price: " << getDiscountPrice() << endl;
		cout << "-------------------------------------" << endl;
	}
};




