#pragma once
#include "Product.h"
#include "FileInterface.h"
#include "Genre.h"

class Movie : public Product, public FileInterface, public Genre {
private:
	string year;
public:
	Movie() : Product(), FileInterface("movies.txt"), Genre("Horror") {
		year = "default";
	}
	Movie(string year) : Product(), FileInterface("movies.txt"), Genre("Horror") {
		this->year = year;
	}
	Movie(string year, string name, double price, double discount) :
		Product(name, price, discount), FileInterface("movies.txt"), Genre("Horror") {
		this->year = year;
	}
	Movie(string year, string name, double price, double discount, string path) :
		Product(name, price, discount), FileInterface(path), Genre("Horror") {
		this->year = year;
	}

	void printDescription() override {
		Product::printDescription();
		cout << "year: " << this->year << endl;
		cout << "-------------------------------------" << endl;
	}

	string getAuthor() { return this->year; }
	void setAuthor(string newAuthor) { this->year = newAuthor; }

	int writeToFile() override {
		if (!isOpen) openFile();
		out << "Movie: " << endl;
		out << "-------------------------------------" << endl;
		out << "Name: " << this->name << endl;
		out << "Price(No discount): " << this->price << endl;
		out << "Discount Percent: " << this->discountPercent << endl;
		out << "Discount amount: " << this->getDiscountAmount() << endl;
		out << "End Price: " << getDiscountPrice() << endl;
		out << "year: " << this->year << endl;
		out << "genre: " << this->genre << endl;
		out << "-------------------------------------" << endl;
		closeFile();
		return 0;
	}


};