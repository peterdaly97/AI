#include "tile.h"

Tile::Tile(sf::Vector2f pos, sf::Font * font) {
	m_tile.setSize(sf::Vector2f(m_width, m_height));
	m_tile.setFillColor(sf::Color::White);
	m_tile.setOutlineColor(sf::Color::Cyan);
	m_tile.setOutlineThickness(2.0f);
	m_tile.setPosition(pos);

	

	m_text.setFont(*font);
	m_text.setPosition(pos);
	m_text.setCharacterSize(16.0f);
	m_text.setFillColor(sf::Color::Black);
}

Tile::~Tile() {}

void Tile::update() {
	
	m_text.setString(std::to_string(m_cost));

	if (m_obstacle)
		m_tile.setFillColor(sf::Color::Red);
	else if (m_start)
		m_tile.setFillColor(sf::Color::Green);
	else if (m_end)
		m_tile.setFillColor(sf::Color::Yellow);
	else
		m_tile.setFillColor(sf::Color::White);
}

void Tile::setCost(int cost) {
	m_cost = cost;
}

void Tile::render(sf::RenderWindow * window) {
	window->draw(m_tile);
	if(!m_obstacle)
		window->draw(m_text);
}

