#ifndef STATION_H
#define STATION_H

#include<string>

class Station{
	std::string name;
	unsigned int sPass, aPass;

	public:	
	enum PassType {STUDENT, ADULT}; // Type of passes available
	Station();
	void set(const std::string&, unsigned, unsigned);
	void update(PassType, int);
	unsigned inStock(PassType) const;
	const std::string& getName() const;
	
};


#endif
