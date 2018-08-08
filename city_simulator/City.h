#ifndef _City
#define _City

#include <vector>
#include "object.h"

class City {
protected:
	std::vector<std::vector<Object*>> Map;
public:
	City();
	bool noTreesAround(int,int);
	void drawCircle(int,int,int,Object*);

	void printCity();
	void generateTrees();
	void live();
	void generateGrass();
	void generateRoads();
	void generatePavements();
	void generateBuildings();
	void generateRiver();
};


#endif 
