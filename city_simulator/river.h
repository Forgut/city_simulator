#ifndef _river
#define _river

#include "object.h"

class River : public Object {
	bool Main;

public:
	River(bool);
	River();
	bool isMain();
	void setPosition(int, int);
};

#endif
