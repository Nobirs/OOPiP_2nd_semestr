#include "Check.h"

// Constructors
Check::Check() 
{
	/* 
	- Default constructor. Creates default Products.
	- Only for tests.......
	*/
	p = new Product();
	this->productName = p->getName();
	this->price = p->getPrice();
	this->count = 1;
	this->overallPrice = calcOverallPrice();
	this->date = "02.03.2024";
	this->time = "15:00";
}

Check::Check(const Product& p, const uint32_t c, string date, string time)
{
	this->productName = p.getName();
	this->price = p.getPrice();
	this->count = c;
	this->date = date;
	this->time = time;
	this->overallPrice = calcOverallPrice();
}

Check::~Check()
{
	delete p; // TODO: think if really needed....
}

void Check::setProductName(const string& name)
{
	if (!name.length()) this->productName = name;
}

void Check::setPrice(const double& price)
{
	if (price > 0) 
	{
		this->price = price;
		this->p->setPrice(price); // TODO: think if needed....
		this->overallPrice = calcOverallPrice(); // update overall price
	}
}

void Check::setCount(const uint32_t& count)
{
	this->count = count;
	this->overallPrice = calcOverallPrice();
}

void Check::setOverallPrice(const double& price)
{
	/*
	- Don't use this method... 
	- Use calcOverallPrice instead! 
	*/
	if (price >= 0) this->overallPrice = price;
}

void Check::setDate(const string& date)
{
	if (!date.length()) this->date = date;
}

void Check::setTime(const string& time)
{
	if (!time.length()) this->time = time;
}

double Check::calcOverallPrice()
{
	return this->price * this->count;
}
