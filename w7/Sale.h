#ifndef _SaLE_H_
#define _SALE_H_

#include <iostream>
#include <vector>
#include "iProduct.h"


namespace w7{
	class Sale{

		std::vector<iProduct*> products;
		double total;

		public:
		Sale(const char * filename);
		void display(std::ostream& os) const;
	};

}



#endif