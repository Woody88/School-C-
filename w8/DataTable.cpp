#include "DataTable.h"
#include <fstream>
#include <iostream>


w8::DataTable::DataTable(std::ifstream& dataFile, int FW, int ND) {
	
}


void class w8::DataTable::display(std::ostream& os) const { }

std::ostream& w8::operator<<(std::ostream&, const DataTable<T>&) { }