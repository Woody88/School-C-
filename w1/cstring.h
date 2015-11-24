#ifndef CSTRING_H
#define CSTRING_H

#include<iostream>

namespace w1 {
	const int MAX = 3;
	class Cstring {
		private:
		char string[MAX+1];
		//Cstring(){};
		public:
		Cstring(){};
		Cstring(char *);
		void display(std::ostream&);
		
	};
	
	std::ostream& operator<<(std::ostream&, Cstring& );
}

#endif
