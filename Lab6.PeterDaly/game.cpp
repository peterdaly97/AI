#include "game.h"

static sf::Int32 MS_PER_UPDATE = 10.0;


Game::Game() : m_window(sf::VideoMode(1500, 1000), "AI") {

	m_window.setFramerateLimit(60);

}

Game::~Game() {

}

void Game::run() {
	m_window.setKeyRepeatEnabled(false);
	while (m_window.isOpen()) {
		update();
		while (m_window.pollEvent(event))
		{
			
			if (event.type == event.MouseButtonReleased && 
				event.mouseButton.button == sf::Mouse::Left) 
			{
				sf::Vector2f mousePos;
				mousePos.x = m_mouse.getPosition(m_window).x / 50;
				mousePos.y = m_mouse.getPosition(m_window).y / 50;
				grid.select(mousePos);
			}
				
		}
		render();
	}
}

void Game::update() {
	grid.update();
	
	if (grid.m_startCalc) {
		grid.setUpHeatMap();
	}

}

void Game::render() {
	m_window.clear();
	
	grid.render(&m_window);

	m_window.display();

}