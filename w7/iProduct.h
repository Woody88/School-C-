#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_

 // Workshop 7 - STL Containers
 // iProduct.h

#include <iostream>
#include <fstream>
#include <iomanip>

 namespace w7 {

     class iProduct {
       public:
        	virtual double getCharge() const = 0;
        	virtual void display(std::ostream&) const = 0;
     };

     class Product : public iProduct {
     	int product_number;
     	float product_cost;

     	public:
     		Product();
     		Product(int, float);
	     	~Product();
	     	virtual double getCharge() const{
	     		return product_cost;
	     	}

	     	virtual void display(std::ostream& os) const { 
	     		os << std::setw(10) << product_number;
	     		os << std::setw(10) << std::fixed << std::setprecision(2) <<  product_cost;
	     	}
     };

     class TaxableProduct : public Product {
     	std::string taxable_code;

	     public:
	     	TaxableProduct(int, float, std::string);
	     	~TaxableProduct();
	     	virtual double getCharge() const{
	     		double charge = Product::getCharge();
	     		if (taxable_code == "HST")
	     			return (charge + (charge * 0.13));
	     		else
	     			return (charge + (charge * 0.08));

	     	}
	     	virtual void display(std::ostream& os) const {
	     		Product::display(os);
	     		os << " ";
	     		os << taxable_code;
	     	}
     	
     };

    std::ostream& operator<<(std::ostream&, const iProduct&); 
    iProduct* readProduct(std::ifstream&);
 }

 #endif