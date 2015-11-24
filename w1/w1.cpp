// Woodson Delhia
// Workshop 1
// W1.cpp

#include<iostream>
#include<cstring>
#include "Process.h"
#include "cstring.h"

using namespace std;



int main(int argc, char *argv[]){
	int i;
	
	if (argc < w1::MAX) {
		cout << "Command Line: " << argv[0] << endl;
		cout << "Insufficient number of arguments (min 1)" << endl; 
		return 1;
	}
	else{
		cout << "Command Line: " << argv[0];
		for(int i = 1; i < argc; i++){
			cout << " " <<argv[i];
		}
		cout << endl;
		cout << "Maximum number of characters stored: " << w1::MAX << endl;
		
		for(int i = 1; i < argc; i++){
			//cout << strlen(argv[i]) << endl;
			if (strlen(argv[i]) >= w1::MAX)
				process(argv[i]);
		}

		
		return 0;
	}
}
