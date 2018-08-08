#include "object.h"

Object::Object() {
	Img = nullptr;
}

sf::RectangleShape* Object::getImg() {
	return Img;
}

void Object::setPosition(int x, int y) {}

bool Object::isVertical() {
	return 0;
}

bool Object::isMain() {
	return 0;
}
