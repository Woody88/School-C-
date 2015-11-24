#include "Item.h"
#include "Utilities.h"
#include <vector>
#include <iomanip>

char Item::delimiter = 0;
size_t Item::field_width = 0;

Item::Item(const std::string& str) {
	name = "";
	source = "";
	destination = "";
	details = "no detailed description";
	code = 1;
		
	std::vector<std::string> tokens;
	Utilities utl(getFieldWidth());
	std::size_t next_pos = 0;
	bool more = true;
	std::string tmpCode, tmpDesc;

	if (!str.empty()) {
		name = utl.nextToken(str, next_pos, more);
		if (name.empty())
			throw std::string(str + "*** no token found before the delimiter ***");

		if (more) {
			source = utl.nextToken(str, next_pos, more);
			if (source.empty())
				throw std::string(str + "*** no token found before the delimiter ***");

		}

		if (more) {
			destination = utl.nextToken(str, next_pos, more);
			if (destination.empty())
				throw std::string(str + "*** no token found before the delimiter ***");

		}

		if (more) {
			tmpCode = utl.nextToken(str, next_pos, more);
			if (tmpCode.empty())
				throw std::string(str + "*** no token found before the delimiter ***");
			else
				code = std::stoi(tmpCode);

		}

		if (more) {
			tmpDesc = utl.nextToken(str, next_pos, more);
			if (!tmpDesc.empty())
				details = tmpDesc;

		}
	}

	if (name.size() > field_width) {
		field_width = name.size();
	}
}
 
bool Item::empty() const {
	return name.empty();
}

void Item::operator++(int) {
	code++;
}

unsigned int Item::getCode() const {
	return code;
}

const std::string& Item::getName() const {
	return name;
}

const std::string& Item::getSource() const {
	return source;
}

const std::string& Item::getDestination() const {
	return destination;
}

void Item::display(std::ostream& os, bool full) const {
	os << std::setw(field_width) << std::left << name;
	os << "[" << std::setw(CODE_WIDTH) << std::setfill('0');
	os << std::right << code << "] ";
	os << std::setfill(' ');
	os << "From " << std::setw(field_width) << std::left << source;
	os << std::left << " To " << destination << std::endl;
	
	if (full) {
		os << std::setw((field_width + CODE_WIDTH + 3)) << std::right << " : ";
		os << std::left << details << std::endl;
	}
}

void Item::setDelimiter(const char del) {
	delimiter = del;
}

size_t Item::getFieldWidth() {
	return field_width;
}
