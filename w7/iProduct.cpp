#include <iostream>
#include <string>
#include "iProduct.h"

using namespace w7;

iProduct* w7::readProduct(std::ifstream& file) { 
	std::string line;
	size_t pst, hst;

	getline(file, line);
	//std::cout << tmp << std::endl;


	// file.clear();
	// file.seekg(std::ios::beg);
	// line = new std::string[nLines];

	// for(int i = 0; i < nLines; i++){
	// 	getline(file, line[i]);
		
	// 	// Looks to see if taxable code is in string
		pst = line.find("P");
		hst = line.find("H");

		if (pst == std::string::npos && hst == std::string::npos) {
			std::size_t  pos = line.find(" ");
			int pNumber = std::stoi( line.substr(0, pos) );
			float pCost = std::stof(line.substr(pos));

			iProduct* product = new Product(pNumber, pCost);

			return product;

		}
		else{
			std::size_t  pos = line.find(" ");
			int pNumber = std::stoi( line.substr(0, pos) );
			float pCost = pst != std::string::npos ? std::stof(line.substr(pos, pst)) : std::stof(line.substr(pos, hst)) ;
			std::string str = pst != std::string::npos ? "PST" : "HST";

			iProduct* product = new TaxableProduct(pNumber, pCost, str);

			return product;

		}
}

std::ostream& w7::operator<<(std::ostream& os, const iProduct& product) {
	os << "helllo world";

	return os;
}

Product::Product(int pNumber, float pCost){
	product_number = pNumber;
	product_cost = pCost;
}

Product::~Product(){ }


TaxableProduct::TaxableProduct(int pNumber, float pCost, std::string str) : Product(pNumber, pCost) {
	taxable_code = str;
}