#include<iostream>
#include<string>
#include "station.h"

// Contructor with 3 arguments
Station::Station() : name(""), sPass(0), aPass(0){}

// set Function 
void Station::set(const std::string& station, unsigned sPass, unsigned aPass){
	this->name = station;
	this->sPass = sPass;
	this->aPass = aPass;
}

// update Function
void Station::update(PassType pass, int n){
	
	switch(pass){
	
	case STUDENT:
		if ( n < 0){
			n = n * -1;
			this->sPass = this->sPass - (unsigned int)n; 
		}
		else
			this->sPass = this->sPass + (unsigned int)n;
		break;
	case ADULT:
		if ( n < 0){
			n = n * -1;
			this->aPass = this->aPass - (unsigned int)n;
		}
		else
			this->aPass = this->aPass + (unsigned int)n;
		break;
	}
}

// inStock Function
unsigned Station::inStock(PassType pass) const{
	if (pass == STUDENT)
		return this->sPass;
	else if (pass == ADULT) 
		return this->aPass;
	else
		return 1;
}

// getName Function
const std::string& Station::getName() const{
	return this->name;
}
