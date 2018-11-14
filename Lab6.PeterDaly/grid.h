#ifndef GRID_H
#define GRID_H

#include "SFML/Graphics.hpp"
#include "tile.h"
#include <vector>
#include <limits>

class Grid
{
public:
	Grid();

	~Grid();

	void update();
	void render(sf::RenderWindow * window);

	void initObstacles();

	void select(sf::Vector2f pos);

	void setUpHeatMap();
	void heatMap(Tile * tile, int x, int y, int cost);
	void heatLoop();

	bool m_startCalc = false;

private:
	int m_width = 30;
	int m_height = 20;
	Tile *m_grid[30][20];

	sf::Keyboard m_keys;
	int m_lastKey = 0;

	int xSelected = 0;
	int ySelected = 0;

	bool m_lastPress = false;

	bool m_start = false;
	bool m_end = false;

	sf::Font m_font;

	std::vector<Tile *> pq;
	std::vector<std::pair<std::vector<Tile *>, int>> qq;
};

#endif //!GRID_H

