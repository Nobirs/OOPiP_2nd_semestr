#include "Department.h"

Department::Department()
{

}

Department::~Department()
{
	products.clear();
}


tuple<Product*, uint32_t> Department::getProduct(string name, uint32_t count) {
	/*
	* Get products from the department when they are selling
	* If not enough - return tuple with zero count
	*/
	for (auto& t : products) {
		if (get<Product*>(t)->getName() == name and get<uint32_t>(t) >= count)
		{
			get<uint32_t>(t) -= count;
			return { get<Product*>(t), count };
		}
	}
	return { nullptr, 0 };
}

void Department::addProduct(Product* p, uint32_t count)
{
	for (auto& t : products) {
		if (get<Product*>(t)->getName() == p->getName())
		{
			get<uint32_t>(t) += count;
			return;
		}
	}
	products.push_back({ p, count });
}
