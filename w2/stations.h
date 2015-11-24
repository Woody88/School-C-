#ifndef STATIONS_H
#define STATIONS_H
#include<string>
#include "station.h"
namespace w2{
	
	class Stations{
		Station* station;
		int station_count;
		std::string filename;
		
		public:
			Stations(char *);
			~Stations();
			void update() const;
			void restock() const;
			void report() const;
	};
}
#endif 
