#include "pavement.h"

extern sf::RectangleShape PavementText;
extern sf::RectangleShape PavementDownText;
extern sf::RectangleShape PavementUpText;
extern sf::RectangleShape PavementLeftText;
extern sf::RectangleShape PavementRightText;

Pavement::Pavement() {
	Img = &PavementText;
}

void Pavement::setPosition(int x,int y) {
	Img->setPosition(x, y);
}
