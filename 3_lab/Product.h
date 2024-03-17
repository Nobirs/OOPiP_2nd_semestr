#pragma once
#include <climits>
#include <string>


#define ullong unsigned long long
#define ULLONG_MAX_BORDER 10000000000000
#define CODE_MAX LLONG_MAX % ULLONG_MAX_BORDER


#include "Countries.h"


using std::string;


enum class ProductTypes {
	Paper, //----- ������
	PaperClips, // ������� ��� �����
	Glue, //------ ����
	Paints, //---- ������
	Brushes, //--- ��������
	Files, //----- �����
	Envelopes, //- ��������
	Notepads, //-- ��������
	Cards, //----- ��������
	Other //------ ������
};


class BaseProduct {
protected:
	string name;
	double price;
};


class Product : BaseProduct
{
private:
	ProductTypes type;
	Countries originCountry;
	ullong barCode;

public:
	//Constructors
	Product();
	Product(string name, ProductTypes t, Countries c,const ullong& code, double p);

	// Destructor
	~Product();

	// Getters
	string getName() const { return this->name; }
	ProductTypes getType() const { return this->type; }
	Countries getOriginCountry() const { return this->originCountry; }
	ullong getBarCode() const { return this->barCode; }
	double getPrice() const { return this->price; }

	// Setters
	void setName(string& name);
	void setType(const ProductTypes& t);
	void setOriginCountry(const Countries& c);
	void setBarCode(const ullong& code);
	void setPrice(const double& p);

	// Useful methods
	ullong correctBarCode(const ullong& code);
};

