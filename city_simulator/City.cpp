#include "City.h"
#include "variables.h"
#include <thread>
#include <Windows.h>

#include "grass.h"
#include "tree.h"
#include "road.h"
#include "pavement.h"
#include "river.h"

#include "pair.h"

City::City() {
	Map = std::vector<std::vector<Object*>>(WindowWidth / BlockSize, std::vector<Object*>(WindowHeight / BlockSize));
}

bool City::noTreesAround(int x, int y) {
	if (x > 0 && Map[x - 1][y]->getImg()->getFillColor() == TreeColor) return false;
	if (x > 0 && y > 0 && Map[x - 1][y - 1]->getImg()->getFillColor() == TreeColor) return false;
	if (x < ArrayX - 1 && Map[x + 1][y]->getImg()->getFillColor() == TreeColor) return false;
	if (x > 0 && y < ArrayY - 1 && Map[x - 1][y + 1]->getImg()->getFillColor() == TreeColor) return false;
	if (y > 0 && Map[x][y - 1]->getImg()->getFillColor() == TreeColor) return false;
	if (x < ArrayX - 1 && y>0 && Map[x + 1][y - 1]->getImg()->getFillColor() == TreeColor) return false;
	if (y < ArrayY - 1 && Map[x][y + 1]->getImg()->getFillColor() == TreeColor) return false;
	if (x < ArrayX - 1 && y < ArrayY - 1 && Map[x + 1][y + 1]->getImg()->getFillColor() == TreeColor) return false;
	return true;
}

void City::generateTrees() {
	std::vector<Pair> Trees, TreesNext;
	for (int i = 0; i < 5; i++) {
		Trees.push_back(Pair(rand() % ArrayX - 1, rand() % ArrayY - 1));
	}
	TreesNext = Trees;
	while (!Trees.empty()) {
		for (auto T : Trees) {
			int X = T.First + ((rand() % 8) - 4);
			int Y = T.Second + ((rand() % 8) - 4);
			if (X >= 0 && X < ArrayX && Y >= 0 && Y < ArrayY && Map[X][Y]->getImg()->getFillColor() == GrassColor && noTreesAround(X, Y)) {
				TreesNext.push_back(Pair(X, Y));
				Map[X][Y] = new Tree();
			}
		}
		Trees.clear();
		Trees = TreesNext;
		TreesNext.resize(TreesNext.size() / 1.1);
		Sleep(100);
	}
	printf("koniec drzew\n");
}

void City::generateGrass() {
	for (int i = 0; i < WindowWidth / BlockSize; i++) {
		for (int j = 0; j < WindowHeight / BlockSize; j++) {
			Map[i][j] = new Grass();
		}
	}
}

void City::generateRoads() {
	srand(time(NULL));
	std::vector<Pair> RoadsToExpand, RoadsToExpandNext;
	{
		for (int TimesToPlaceSeeds = 0; TimesToPlaceSeeds < 3; TimesToPlaceSeeds++) {
			int seed_x = rand() % 80, seed_y = rand() % 60;
			Map[seed_x][seed_y] = new Road(true);
			RoadsToExpand.push_back(Pair(seed_x, seed_y));
		}
	}
	while (!RoadsToExpand.empty()) {
		for (auto R : RoadsToExpand) {
			Sleep(3);
			int
				x = R.First,
				y = R.Second;
			if (Map[x][y]->isVertical()) {
				if (y > 0 && Map[x][y - 1]->getImg()->getFillColor() != RoadColor) {
					Map[x][y - 1] = new Road(true);
					RoadsToExpandNext.push_back(Pair(x, y - 1));
				}
				if (y < ArrayY - 1 && Map[x][y + 1]->getImg()->getFillColor() != RoadColor) {
					Map[x][y + 1] = new Road(true);
					RoadsToExpandNext.push_back(Pair(x, y + 1));
				}
				if (x > 0 && Map[x - 1][y]->getImg()->getFillColor() != RoadColor && Map[x - 1][y]->getImg()->getFillColor() != RiverColor) {
					if (rand() % 100 < chance) {
						Map[x - 1][y] = new Road(false);
						RoadsToExpandNext.push_back(Pair(x - 1, y));
					}
				}
				if (x < ArrayX - 1 && Map[x + 1][y]->getImg()->getFillColor() != RoadColor &&  Map[x + 1][y]->getImg()->getFillColor() != RiverColor) {
					if (rand() % 100 < chance) {
						Map[x + 1][y] = new Road(false);
						RoadsToExpandNext.push_back(Pair(x + 1, y));
					}
				}
			}
			else {
				if (x > 0 && Map[x - 1][y]->getImg()->getFillColor() != RoadColor) {
					Map[x - 1][y] = new Road(false);
					RoadsToExpandNext.push_back(Pair(x - 1, y));
				}
				if (x < ArrayX - 1 && Map[x + 1][y]->getImg()->getFillColor() != RoadColor) {
					Map[x + 1][y] = new Road(false);
					RoadsToExpandNext.push_back(Pair(x + 1, y));
				}
				if (y > 0 && Map[x][y - 1]->getImg()->getFillColor() != RoadColor && Map[x][y - 1]->getImg()->getFillColor() != RiverColor) {
					if (rand() % 100 < chance) {
						Map[x][y - 1] = new Road(true);
						RoadsToExpandNext.push_back(Pair(x, y - 1));
					}
				}
				if (y < ArrayY - 1 && Map[x][y + 1]->getImg()->getFillColor() != RoadColor && Map[x][y + 1]->getImg()->getFillColor() != RiverColor) {
					if (rand() % 100 < chance) {
						Map[x][y + 1] = new Road(true);
						RoadsToExpandNext.push_back(Pair(x, y + 1));
					}
				}
			}
		}
		RoadsToExpand = RoadsToExpandNext;
		RoadsToExpandNext.clear();
	}
	printf("koniec drog\n");

}

void City::generatePavements() {

	std::vector<Pair> Roads;
	int check = 0;
	while (true) {
		for (auto R : Roads) {
			int x = R.First, y = R.Second;
			if (Map[x][y]->isVertical()) {
				if (x > 0 && Map[x - 1][y]->getImg()->getFillColor() != RoadColor) {
					if (Map[x-1][y]->getImg()->getFillColor()!=RiverColor)
					Map[x - 1][y] = new Pavement();
				}
				if (x < ArrayX - 1 && Map[x + 1][y]->getImg()->getFillColor() != RoadColor) {
					if (Map[x + 1][y]->getImg()->getFillColor() != RiverColor)
					Map[x + 1][y] = new Pavement();
				}
			}
			else {
				if (y > 0 && Map[x][y - 1]->getImg()->getFillColor() != RoadColor) {
					if (Map[x][y-1]->getImg()->getFillColor() != RiverColor)
					Map[x][y - 1] = new Pavement();
				}
				if (y < ArrayY - 1 && Map[x][y + 1]->getImg()->getFillColor() != RoadColor) {
					if (Map[x][y+1]->getImg()->getFillColor() != RiverColor)
					Map[x][y + 1] = new Pavement();
				}
			}
		}

		Roads.clear();

		for (int i = 0; i < ArrayX; i++) {
			for (int j = 0; j < ArrayY; j++) {
				if (Map[i][j]->getImg()->getFillColor() == RoadColor) {
					if (Map[i][j]->isVertical()) {
						if ((i > 0 && Map[i - 1][j]->getImg()->getFillColor() != PavementColor && Map[i - 1][j]->getImg()->getFillColor() != RoadColor) || i < ArrayX - 1 && Map[i + 1][j]->getImg()->getFillColor() != PavementColor && Map[i + 1][j]->getImg()->getFillColor() != RoadColor) {
							Roads.push_back(Pair(i, j));
						}
					}
					else {
						if ((j > 0 && Map[i][j - 1]->getImg()->getFillColor() != PavementColor && Map[i][j - 1]->getImg()->getFillColor() != RoadColor) || j < ArrayY - 1 && Map[i][j + 1]->getImg()->getFillColor() != PavementColor && Map[i][j + 1]->getImg()->getFillColor() != RoadColor) {
							Roads.push_back(Pair(i, j));
						}
					}
				}
			}
		}
		if (Roads.empty()) {
			if (check == 5) break;
			check++;
		}
		else check = 0;


	}
	printf("koniec chodnikow\n");
}

void City::generateBuildings() {
	std::vector<Pair> Pavements{ Pair(0,0) };
	while (!Pavements.empty()) {
		Pavements.clear();
		for (int i = 0; i < ArrayX; i++) {
			for (int j = 0; j < ArrayY; j++) {
				if (Map[i][j]->getImg()->getFillColor() == PavementColor) {
					Pavements.push_back(Pair(i, j));
				}
			}
		}



	}
}

void City::drawCircle(int X, int Y, int Radius,Object* Tile) {
	for (int i = X - Radius; i < X + Radius; i++) {
		for (int j = Y - Radius; j < Y + Radius; j++) {
			if (i >= 0 && j >= 0 && i < ArrayX && j < ArrayY) {
				if ((i - X)*(i - X) + (j - Y)*(j - Y) <= (Radius)*(Radius)) Map[i][j] = Tile;
			}
		}
	}
}

void drawTheCoordinates(int &RandX, int &RandY) {
	int
		Rand = rand() % 2;

	switch (Rand) {
	case 0: {
		RandX = rand() % ArrayX / 2;
		RandY = 0;
		break;
	}
	case 1: {
		RandX = 0;
		RandY = ArrayY / 2;
		break;
	}
	}
}

void City::generateRiver() {
	Pair RiverToGo;
	int RandX, RandY;
	drawTheCoordinates(RandX, RandY);

	Map[RandX][RandY] = new River();
	RandX -= 5;
	RandY -= 5;
	RiverToGo = Pair(RandX, RandY);
	while (RandX>-10 && RandX<ArrayX+10 && RandY>-10 && RandY<ArrayY+10) {
		RandX += rand() % 5-1;
		RandY += rand() % 5-1;
		printf("%i , %i\n", RandX, RandY);
		if (RandX >= 0 && RandX < ArrayX && RandY >= 0 && RandY < ArrayY) {
			Map[RandX][RandY] = new River();
			drawCircle(RandX, RandY, 3, new River());
		}
		Sleep(30);
	}

}

void City::live() {
	srand(time(NULL));
	generateGrass();

	sf::Thread printingThread(&City::printCity, this);
	printingThread.launch();

	generateRiver();

	sf::Thread generatingBuildingsThread(&City::generateBuildings, this);
	sf::Thread generatingTreesThread(&City::generateTrees, this);
	sf::Thread generatingRoadsThread(&City::generateRoads, this);
	sf::Thread generatingPavementsThread(&City::generatePavements, this);

	generatingTreesThread.launch();
	generatingRoadsThread.launch();
	generatingPavementsThread.launch();
	//generatingBuildingsThread.launch();

}

void City::printCity() {

	sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "CITY");

	Map[60][50] = new Grass();

	int
		vector_width = WindowWidth / BlockSize,
		vector_height = WindowHeight / BlockSize;
	sf::Event event;

	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(sf::Color(GrassColor));
		for (int i = 0; i < vector_width; i++) {
			for (int j = 0; j < vector_height; j++) {
				if (Map[i][j] != nullptr) {
					Map[i][j]->setPosition(i*BlockSize, j*BlockSize);
					window.draw(*Map[i][j]->getImg());
				}
			}
		}
		window.display();
	}
}