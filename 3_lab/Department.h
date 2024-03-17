#pragma once
#include <vector>
#include <tuple>


using std::vector;
using std::tuple;
using std::get;


#include "Product.h"


class Department
{
private:
	vector<tuple<Product*, uint32_t>> products;
	
public:
	// Constructor
	Department();

	// Destructor
	~Department();

	// Getters
	vector<tuple<Product*, uint32_t>>* getProducts() { return &products; }

	// Useful methods
	bool isEmpty() { return products.size() != 0; }
	size_t getSize() { return products.size(); }
	tuple<Product*, uint32_t> getProduct(string name, uint32_t count);
	void addProduct(Product* p, uint32_t count);
};

