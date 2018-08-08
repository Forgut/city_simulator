#ifndef _object
#define _object 

#include "SFML\Graphics.hpp"

class Object {
protected:
	sf::RectangleShape *Img;
public:
	Object();
	sf::RectangleShape* getImg();
	virtual void setPosition(int, int);

	//for Road
	virtual bool isVertical(); 

	//for River
	virtual bool isMain();

};

#endif
