//#include "textures.h"
#include "variables.h"
#include "textures.h"
#include "SFML\Graphics.hpp"

sf::RectangleShape
GrassText,
TreeText,
RoadText,
PavementText,
BuildingText,
RiverText;

void initTextures() {
	sf::RectangleShape Pattern(sf::Vector2f(BlockSize,BlockSize));

	GrassText = Pattern;
	GrassText.setFillColor(GrassColor);

	TreeText = Pattern;
	TreeText.setFillColor(TreeColor);

	RoadText = Pattern;
	RoadText.setFillColor(RoadColor);

	PavementText = Pattern;
	PavementText.setFillColor(PavementColor);

	BuildingText = Pattern;
	BuildingText.setFillColor(BuildingColor);

	RiverText = Pattern;
	RiverText.setFillColor(RiverColor);
}