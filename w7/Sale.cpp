#include <iomanip>
#include "iProduct.h"
#include "Sale.h"

using namespace w7;


Sale::Sale(const char* filename) { 
	//std::cout << "in Sale constructor" << std::endl; 
	std::ifstream file(filename);
 	std::string s;
	int nLines = 0;
	
	if(!file.is_open())
		throw "Could not open file!";
	else{
		while(!file.eof()){
		 	products.push_back( readProduct(file) );
		}
		
	}

	for (int i = 0; i < products.size(); ++i)
	{
		total += products[i]->getCharge();
	}
}

void Sale::display(std::ostream& os) const {
	os << "Product No" << std::setw(10) << "Cost" << " Taxable" << std::endl;

	for (int i = 0; i < products.size(); ++i)
	{
		products[i]->display(os);
		os << std::endl;

		// This does not trigger << operator function...??
		os << *(products[i]);
	}

	os << std::setw(10) << "Total";
	os << std::setw(10) << std::fixed << std::setprecision(2) << total << std::endl;
}
