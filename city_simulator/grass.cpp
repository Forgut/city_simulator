#include "grass.h"

extern sf::RectangleShape GrassText;

Grass::Grass() {
	Img = &GrassText;
	Img->setPosition(sf::Vector2f(0, 0));
}

void Grass::setPosition(int x, int y) {
	Img->setPosition(sf::Vector2f(x, y));
}