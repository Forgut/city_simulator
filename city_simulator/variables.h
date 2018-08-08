#ifndef _variables
#define _variables 

#include "SFML\Graphics\Color.hpp"

const int
WindowWidth = 800,
WindowHeight = 600,
BlockSize = 10,
ArrayX = WindowWidth / BlockSize,
ArrayY = WindowHeight / BlockSize,
chance = 4; //%

const sf::Color
GrassColor = sf::Color(0, 240, 0, 255),
TreeColor = sf::Color(0, 150, 0, 255),
RoadColor = sf::Color(45, 45, 45, 255),
PavementColor = sf::Color(60,60,60,255),
BuildingColor = sf::Color(170,100,50,255),
RiverColor = sf::Color(0, 0, 200, 255);



#endif 

