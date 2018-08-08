#include "tree.h"

extern sf::RectangleShape TreeText;

Tree::Tree() {
	Img = &TreeText;
	Img->setPosition(sf::Vector2f(0, 0));

}
void Tree::setPosition(int x, int y) {
	Img->setPosition(sf::Vector2f(x, y));
}