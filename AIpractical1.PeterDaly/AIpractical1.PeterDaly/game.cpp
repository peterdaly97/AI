#include "game.h"

static sf::Int32 MS_PER_UPDATE = 10.0;


Game::Game() : m_window(sf::VideoMode(3840, 2160), "AI") {
		
	m_window.setFramerateLimit(60);

	enemies.push_back(new Enemy(behaviour::SEEK, sf::Vector2f(1000, 500), 2.5));
	enemies.push_back(new Enemy(behaviour::PATROL, sf::Vector2f(100, 800), 2.5));
	enemies.push_back(new Enemy(behaviour::PURSUE, sf::Vector2f(1600, 100), 2.5));
	enemies.push_back(new Enemy(behaviour::ARRIVE, sf::Vector2f(3000, 200), 5.0));
	enemies.push_back(new Enemy(behaviour::ARRIVE, sf::Vector2f(3000, 1800), 10.0));


	for (Enemy* enemy : enemies) {
		enemyPos.push_back(&enemy->m_position);
	}
	
}

Game::~Game() {

}

void Game::run() {

	while (m_window.isOpen()) {
		update();
		render();
	}
}

void Game::update() {
	
	player.update();
	for (Enemy* enemy : enemies) {
		enemy->update(player.m_position, player.m_velocity);
		enemy->avoid(enemyPos);
	}
}

void Game::render() {
	m_window.clear();
	player.render(m_window);
	for (Enemy* enemy : enemies) {
		enemy->render(m_window);
	}
	m_window.display();
	
}