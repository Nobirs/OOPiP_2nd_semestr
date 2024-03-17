#include "StoreBasket.h"

StoreBasket::StoreBasket()
{
}

StoreBasket::~StoreBasket()
{
}

void StoreBasket::addProduct(Product* p, uint32_t count)
{
	for (auto& t : products) {
		if (get<Product*>(t)->getName() == p->getName()) {
			get<uint32_t>(t) += count;
			updateCheck();
			return;
		}
	}
	products.push_back({ p, count });
	updateCheck();

}

void StoreBasket::updateCheck()
{
	check = TotalCheck();
	for (const auto& t : products)
	{
		uint32_t count = std::get<uint32_t>(t);
		const Product* p = std::get<Product*>(t);
		Check* ch = new Check(*p, count, getCurrLocalDate(), getCurrLocalTime());
		check.addCheck(ch);
	}
}
