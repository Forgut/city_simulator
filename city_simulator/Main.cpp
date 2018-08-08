#include <SFML/Graphics.hpp>
#include "object.h"
#include "grass.h"
#include "variables.h"
#include "textures.h"
#include "City.h"
#include <thread>



int main()
{
	initTextures();
	City b;
	b.live();
	return 0;
}