#ifndef TILE_H
#define TILE_H

#include "SFML/Graphics.hpp"
#include <iostream>

class Tile
{
public:
	Tile(sf::Vector2f pos, sf::Font * font);

	~Tile();

	void update();

	void render(sf::RenderWindow * window);

	void setCost(int cost);

	bool m_obstacle = false;

	bool m_start = false;
	bool m_end = false;

	int m_cost = 0;
	int m_integration = 0;
	sf::RectangleShape m_tile;

private:
	int m_width = 50;
	int m_height = 50;
	sf::Text m_text;
	
	
};

#endif //!GRID_H


