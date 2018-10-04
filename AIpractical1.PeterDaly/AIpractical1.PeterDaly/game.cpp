#include "game.h"

static sf::Int32 MS_PER_UPDATE = 10.0;


Game::Game() : m_window(sf::VideoMode(2048, 1080), "AI") {
	fleeEnemy.m_position = sf::Vector2f(1000, 500);
}

Game::~Game() {

}

void Game::run() {
	sf::Clock clock;
	sf::Int32 lag = 0;

	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();

		lag += dt.asMilliseconds();

		while (lag > MS_PER_UPDATE)
		{
			update(dt);
			lag -= MS_PER_UPDATE;
		}
		update(dt);
		render();
	}
}

void Game::update(sf::Time dt) {
	
	player.update(dt);
	seekEnemy.update(player.m_position);
	wanderEnemy.update(player.m_position);
	fleeEnemy.update(player.m_position);
}

void Game::render() {
	m_window.clear();
	player.render(m_window);
	wanderEnemy.render(m_window);
	seekEnemy.render(m_window);
	fleeEnemy.render(m_window);
	m_window.display();
	
}