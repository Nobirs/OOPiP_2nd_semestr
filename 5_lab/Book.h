#pragma once
#include "FileInterface.h"
#include "Product.h"
#include "Genre.h"


class Book : public Product, public FileInterface, public Genre {
private:
	string author;
public:
	Book() : Product(), FileInterface("books.txt"), Genre("Horror") {
		author = "default";
	}
	Book(string author) : Product(), FileInterface("books.txt"), Genre("Horror") {
		this->author = author;
	}
	Book(string author, string name, double price, double discount) :
		Product(name, price, discount), FileInterface("books.txt"), Genre("Horror") {
		this->author = author;
	}
	Book(string author, string name, double price, double discount, string path) :
		Product(name, price, discount), FileInterface(path), Genre("Horror") {
		this->author = author;
	}

	void printDescription() override {
		Product::printDescription();
		cout << "author: " << this->author << endl;
		cout << "-------------------------------------" << endl;
	}

	int writeToFile() override {
		if (!isOpen) openFile();
		out << "Book: " << endl;
		out << "-------------------------------------" << endl;
		out << "Name: " << this->name << endl;
		out << "Price(No discount): " << this->price << endl;
		out << "Discount Percent: " << this->discountPercent << endl;
		out << "Discount amount: " << this->getDiscountAmount() << endl;
		out << "End Price: " << getDiscountPrice() << endl;
		out << "year: " << this->author << endl;
		out << "genre: " << this->genre << endl;
		out << "-------------------------------------" << endl;
		closeFile();
		return 0;
	}
};