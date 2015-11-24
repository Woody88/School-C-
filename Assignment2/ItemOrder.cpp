#include "ItemOrder.h"
#include "Utilities.h"
#include <iomanip>

ItemOrder::ItemOrder(const std::string& str) {
	code = 0;
	filled = false;
	if (!str.empty()) 
		name = str;
}
 
bool ItemOrder::asksFor(const Item& item) const {
	return true;
}

bool ItemOrder::isFilled() const {
	return filled;
}

void ItemOrder::fill(const unsigned int itemCode) {
	code = itemCode;
	filled = true;
}

void ItemOrder::clear() {
	code = 0;
	filled = false;
}

const std::string& ItemOrder::getName() const {
	return name;
}

void ItemOrder::display(std::ostream& os) const {
	if (filled)
		os << "+ ";
	else
		os << "- ";
	
	os << "[" << std::setw(CODE_WIDTH) << std::setfill('0');
	os << std::right << code << "]" << " ";
	os << name << std::endl;
	os << std::setfill(' ');

	/*int CODE_WIDTH = 5;
	os << std::setw(10) << std::left << name;
	os << "[" << std::setw(CODE_WIDTH) << std::setfill('0');
	os << std::right << code << "]" << " ";*/
}