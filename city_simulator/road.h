#ifndef _road
#define _road

#include "object.h"

class Road : public Object {
	bool UpDown; //if true road is vertical, if false horizontal
public:
	Road(bool);
	void setPosition(int, int);
	bool isVertical();
};


#endif 

