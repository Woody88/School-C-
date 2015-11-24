#include<iostream>
#include<iomanip>
#include<fstream>
#include "stations.h"

// Contructor with file argument 
w2::Stations::Stations(char* file_name ){

	char delimiter;
	station = nullptr;
	this->filename = file_name;
	
	std::ifstream file;
	file.open(filename);

	if (file.is_open()){
		file >> station_count >> delimiter;
		station = new Station[station_count];

		for(int i = 0; i < station_count; i++){
			unsigned sPass, aPass;
			std::string name;
			
			getline(file,name, delimiter);
			file >> sPass >> aPass;
			station[i].set(name, sPass, aPass);
		}
	}	
	file.close();
}


// Decontructor
w2::Stations::~Stations(){
	std::ofstream file;
	file.open(filename);

	if (file.is_open()) {
		file << station_count << ";";
		for(int i = 0; i < station_count; i++){
			file << station[i].getName() << ";" << station[i].inStock(Station::PassType::STUDENT) << " " << station[i].inStock(Station::PassType::ADULT);
		}
	}
	file.close();


}

// update Function
void w2::Stations::update() const{
	std::cout << "Passes Sold :" << std::endl;
	std::cout << "-------------" << std::endl;

	for(int i = 0; i < station_count; i++){
		int sPass, aPass;
		
		// Student Passes Sold, value multiple by -1 
		std::cout << station[i].getName() << std::endl;
		std::cout << std::right << std::setw(9) <<  "Student";
		std::cout << " Passes sold : ";
		std::cin >> sPass;
		sPass = sPass * -1;
		station[i].update(Station::PassType::STUDENT, sPass);
		
		// Adult Passes Sold, value multiple by -1
		std::cout << std::right << std::setw(9) <<  "Adult"; 
		std::cout << " Passes sold : ";
		std::cin >> aPass;
		aPass = aPass * -1;
		station[i].update(Station::PassType::ADULT, aPass);
	}
	std::cout << std::endl;
}

// restock Function
void w2::Stations::restock() const{
    std::cout << "Passes Added :" << std::endl;
	std::cout << "-------------" << std::endl;

	for(int i = 0; i < station_count; i++){
		int sPass, aPass;

		std::cout << station[i].getName() << std::endl;
		std::cout << std::right << std::setw(9) << "Student"; 
		std::cout <<" Passes added : ";
		std::cin >> sPass;
		station[i].update(Station::PassType::STUDENT, sPass);

		std::cout << std::right << std::setw(9) << "Adult"; 
		std::cout << " Passes added : ";
		std::cin >> aPass;
		station[i].update(Station::PassType::ADULT, aPass);
	}

}

// report Function
void w2::Stations::report() const{
	std::cout << "Passes in Stock : Student Adult" << std::endl;
	std::cout << "-------------------------------" << std::endl;

	for(int i = 0; i < station_count; i++){
		
		std::cout << std::left << std::setw(20) << station[i].getName();
		std::cout << std::right << std::setw(6) << station[i].inStock(Station::PassType::STUDENT);
		std::cout << std::setw(6);
		std::cout << station[i].inStock(Station::PassType::ADULT);
		std::cout << std::endl;
	}
}

