#include "road.h"

extern sf::RectangleShape RoadText;

Road::Road(bool UpDown) {
	Img = &RoadText;
	Img->setPosition(sf::Vector2f(0, 0));
	this->UpDown = UpDown;
}

void Road::setPosition(int x, int y) {
	Img->setPosition(sf::Vector2f(x, y));
}

bool Road::isVertical() {
	return UpDown;
}
