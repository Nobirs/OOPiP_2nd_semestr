#pragma once
#include <vector>
#include <tuple>


using std::vector;
using std::tuple;
using std::get;

#include "TotalCheck.h"
#include "CurrentTime.h"

class StoreBasket
{
private:
	vector<tuple<Product*, uint32_t>> products;
	TotalCheck check;

public:
	// Constructor
	StoreBasket();

	// Destructor
	~StoreBasket();

	// getters
	TotalCheck* getTotalCheck() { return &check; }

	// Useful methods
	void addProduct(Product* p, uint32_t count);
	void updateCheck();
};

