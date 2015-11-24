#include "cstring.h"
#include<iostream>
#include<cstring>

using namespace w1;

Cstring::Cstring(char *s){
	std::strncpy(string, s, MAX);
	
}
void Cstring::display(std::ostream& os) {
	std::cout << string << std::endl;
}

namespace w1{
std::ostream& operator<<(std::ostream& os, Cstring& obj){	
	static int obj_count;
	 os << obj_count++ << ": ";
	 obj.display(os);
}
}
