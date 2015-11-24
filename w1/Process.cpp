#include "Process.h"
#include "cstring.h"
#include<iostream>

using namespace w1;

void process(char *s) {
	Cstring c_obj (s);
	
	std::cout << c_obj;
}
