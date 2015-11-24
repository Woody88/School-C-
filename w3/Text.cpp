#include<iostream>
#include<string>
#include<fstream>
#include "Text.h"

using namespace w3;

// Default Constructor
Text::Text(){
	strings = nullptr;
	record_count = 0;
}

// Construct with one argument
Text::Text(const std::string& s){
	std::ifstream file;

	file.open(s);
	if (file.is_open()){
		file.seekg(0, file.end);
		record_count = file.tellg();
		file.seekg(0, file.beg);
		strings = new std::string[record_count];
		for(int i = 0; i < record_count; i++){
			getline(file, strings[i]);
		}
	}
	file.close();
}

// Destructor 
Text::~Text(){
	if	(strings != nullptr){
		delete [] strings;
	}
}

// Copy Constructor 
Text::Text(const Text& cpy_obj){
	record_count = cpy_obj.record_count;
	strings = new std::string[record_count];
	for(int i = 0; i < record_count; i++){
		strings[i] = cpy_obj.strings[i];
	}
}

// Move Constructor
Text::Text(Text&& cpy_obj){	
	record_count = cpy_obj.record_count;
	strings = new std::string[record_count];
	for(int i = 0; i < record_count; i++){
		strings[i] = cpy_obj.strings[i];
	}

	cpy_obj.strings = nullptr;
	cpy_obj.record_count = 0;
}

// Copy Assignment Operator
Text& Text::operator=(const Text& cpy_obj){
	if (this != &cpy_obj){
		delete[] strings;
		record_count = 0;
		
		record_count = cpy_obj.record_count;
		strings = new std::string[record_count];

		for(int i = 0; i < record_count; i++){
			this->strings[i] = cpy_obj.strings[i];
		}
	}
	else{
		*this = Text();
	}
	return *this;
}

// Move Assignment Operator
Text& Text::operator=(Text&& cpy_obj){
	if ( this != &cpy_obj ){
		record_count = cpy_obj.record_count;
		strings = new std::string[record_count];
		
		for(int i = 0; i < record_count; i++){
			this->strings[i] = cpy_obj.strings[i];
		}

		cpy_obj.strings = nullptr;
		cpy_obj.record_count = 0;
	}	

	return *this;
}

// Return Size Function 
size_t Text::size() const{
	return record_count;
}

