#ifndef _grass
#define _grass

#include "object.h"

class Grass : public Object {
public:
	Grass();
	void setPosition(int, int);
};

#endif

