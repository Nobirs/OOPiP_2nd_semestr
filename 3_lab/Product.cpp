#include "Product.h"

Product::Product() {
	// Default constructor just if needed
	this->name = "simple paper";
	this->type = ProductTypes::Paper;
	this->originCountry = Countries::USA;
	this->barCode = CODE_MAX;
	this->price = 4.99;
}


Product::Product(string name, ProductTypes t, Countries c,const ullong& code, double p) {
	this->name = name;
	this->type = t;
	this->originCountry = c;
	setBarCode(code);
	setPrice(p);
}


Product::~Product() {
	// Nothing to do....
}


ullong Product::correctBarCode(const ullong& code) {
	return code % ULLONG_MAX_BORDER;
}


void Product::setName(string& name) {
	this->name = name.length() > 0 ? name : "empty";
}


void Product::setType(const ProductTypes& t)
{
	this->type = t;
}


void Product::setOriginCountry(const Countries& c)
{
	this->originCountry = c;
}


void Product::setBarCode(const ullong& code)
{
	this->barCode = correctBarCode(code);
}


void Product::setPrice(const double& p)
{
	this->price = p >= 0 ? p : -p;
}