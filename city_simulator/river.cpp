#include "river.h"

extern sf::RectangleShape RiverText;

River::River(bool isMain) {
	Main = isMain;
	Img = &RiverText;
	Img->setPosition(sf::Vector2f(0, 0));
}

River::River() {
	Main = true;
	Img = &RiverText;
	Img->setPosition(sf::Vector2f(0, 0));
}

void River::setPosition(int x, int y) {
	Img->setPosition(sf::Vector2f(x, y));
}

bool River::isMain() {
	return Main;
}



