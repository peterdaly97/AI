#include "tile.h"

Tile::Tile(sf::Vector2f pos, sf::Font * font) {
	m_tile.setSize(sf::Vector2f(m_width, m_height));
	m_tile.setFillColor(sf::Color::White);
	m_tile.setOutlineColor(sf::Color::Cyan);
	m_tile.setOutlineThickness(2.0f);
	m_tile.setPosition(pos);

	m_line.setPosition(sf::Vector2f(pos.x + (m_width / 2), pos.y + (m_height / 2)));
	m_line.setSize(sf::Vector2f(25, 3));
	
	m_text.setFont(*font);
	m_text.setPosition(pos);
	m_text.setCharacterSize(16.0f);
	m_text.setFillColor(sf::Color::Black);

}

Tile::~Tile() {}

void Tile::setLine(float rot) {
	m_line.setRotation(rot);;
	m_line.setOutlineColor(sf::Color::Black);
	m_line.setFillColor(sf::Color::Black);
}

void Tile::update() {
	
	m_text.setString(std::to_string(m_cost));

	if (m_obstacle)
		m_tile.setFillColor(sf::Color::Red);
	else if (m_start)
		m_tile.setFillColor(sf::Color::Green);
	else if (m_end)
		m_tile.setFillColor(sf::Color::Yellow);
	else
		m_tile.setFillColor(sf::Color(255 - (m_cost * 5), 255 - (m_cost * 5), 255, 255));
}

void Tile::setCost(int cost) {
	m_cost = cost;
}

void Tile::render(sf::RenderWindow * window) {
	window->draw(m_tile);
	
	if(!m_obstacle && !m_start && !m_end)
		window->draw(m_line);
		window->draw(m_text);
}

