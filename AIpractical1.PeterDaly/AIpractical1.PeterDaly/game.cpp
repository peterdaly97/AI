#include "game.h"

static sf::Int32 MS_PER_UPDATE = 10.0;


Game::Game() : m_window(sf::VideoMode(2048, 1080), "AI") {
	fleeEnemy.m_position = sf::Vector2f(1000, 500);
	m_window.setFramerateLimit(60);
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
	rect = sf::FloatRect(player.m_position.x, player.m_position.y, player.m_sprite.getGlobalBounds().width * 0.5, player.m_sprite.getGlobalBounds().height * 0.5);
	seekEnemy.update(player.m_position, player.m_velocity);
	wanderEnemy.update(player.m_position, player.m_velocity);
	fleeEnemy.update(player.m_position, player.m_velocity);
	if (seekEnemy.avoid(rect)) {
		std::cout << "Hit" << std::endl;
	}
}

void Game::render() {
	m_window.clear();
	player.render(m_window);
	wanderEnemy.render(m_window);
	seekEnemy.render(m_window);
	fleeEnemy.render(m_window);
	m_window.display();
	
}