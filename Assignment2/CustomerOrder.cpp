#include "CustomerOrder.h"
#include "ItemOrder.h"
#include "Item.h"
#include "Utilities.h"
#include <iomanip>
#include <vector>

std::size_t CustomerOrder::field_width = 0;
char CustomerOrder::delimiter = '\0';

CustomerOrder::CustomerOrder(const std::string& str)
{
	nOrders = 0;
	order = nullptr;

	std::vector<std::string> items;
	Utilities utl(field_width);
	std::size_t next_pos = 0;
	bool more = true;

	if (!str.empty()) {

		name = utl.nextToken(str, next_pos, more);
		if (name.empty())
			throw  std::string(str + "*** no token found before the delimiter ***");

		if (more) {
			product = utl.nextToken(str, next_pos, more);
			if (product.empty())
				throw std::string(str + "*** no token found before the delimiter ***");
		}

		if (more) {
			std::string tmpItem = utl.nextToken(str, next_pos, more);
			if (tmpItem.empty())
				throw std::string("***33 no token found before the delimiter ***");
			items.push_back(tmpItem);
		}

		while (more) {
			std::string tmpItem = utl.nextToken(str, next_pos, more);
			if (!tmpItem.empty())
				items.push_back(tmpItem);
			else
				more = false;
		} 

		nOrders = items.size();
		order = new ItemOrder[nOrders];
		for (int i = 0; i < nOrders; i++)
		{
			order[i] = ItemOrder(items[i]);
		}
	}

	field_width = utl.getFieldWidth();
}

CustomerOrder::CustomerOrder(const CustomerOrder&)
{
	throw ("Customer Orders Cannot Be Duplicate");
}

CustomerOrder::CustomerOrder(CustomerOrder&& cust)
{
	name = cust.name;
	product = cust.product;
	nOrders = cust.nOrders;
	if (cust.order != nullptr)
		order = cust.order; 
	cust.name.clear();
	cust.product.clear();
	cust.nOrders = 0;
	cust.order = nullptr;
}

CustomerOrder&& CustomerOrder::operator=(CustomerOrder&& cust)
{
	if (this != &cust)
	{
		name = cust.name;
		product = cust.product;
		nOrders = cust.nOrders;
		if (cust.order != nullptr)
			order = cust.order;
		cust.name.clear();
		cust.product.clear();
		cust.nOrders = 0;
		cust.order = nullptr;
	}

	return std::move(*this);
}

CustomerOrder::~CustomerOrder()
{

}

unsigned int CustomerOrder::noOrders() const
{
	return nOrders;
}

const std::string& CustomerOrder::operator[](unsigned int i) const
{
	if (i >= nOrders)
		throw ("Out of Bounds");

	return order[i].getName();
}

void CustomerOrder::fill(Item& item)
{
	for (int i = 0; i < nOrders; i++)
	{
		if (order[i].getName() == item.getName())
		{
			order[i].fill(item.getCode());
			item++;
		}
	}
}

void CustomerOrder::remove(Item& item)
{
	for (int i = 0; i < nOrders; i++)
	{
		if (order[i].getName() == item.getName())
		{
			order[i].clear();
		}
	}
}

bool CustomerOrder::empty() const
{
	return (nOrders == 0) && (order == nullptr) ? true : false;
}

void CustomerOrder::display(std::ostream& os) const
{
	os << std::setw(field_width) << std::left << name << ": ";
	os << std::setw(field_width) << std::left << product << std::endl;
	for (int i = 0; i < nOrders; i++)
	{
		order[i].display(os);
		
	}
}

void CustomerOrder::setDelimiter(const char c)
{
	delimiter = c;
}

