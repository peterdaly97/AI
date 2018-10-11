#include "game.h"

static sf::Int32 MS_PER_UPDATE = 10.0;


Game::Game() : m_window(sf::VideoMode(3840, 2160), "AI") {
	fleeEnemy.m_position = sf::Vector2f(1000, 500);
	arriveEnemySlow.m_position = sf::Vector2f(3000, 200);
	arriveEnemyFast.m_position = sf::Vector2f(3000, 1800);
	wanderEnemy.m_position = sf::Vector2f(100, 800);
	m_window.setFramerateLimit(60);

	arriveEnemySlow.MAX_FORWARD_SPEED = 5.0f;
	arriveEnemyFast.MAX_FORWARD_SPEED = 10.0f;

	enemyPos.push_back(&fleeEnemy.m_position);
	enemyPos.push_back(&wanderEnemy.m_position);
	enemyPos.push_back(&seekEnemy.m_position);
	enemyPos.push_back(&arriveEnemySlow.m_position);
	enemyPos.push_back(&arriveEnemyFast.m_position);


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
	seekEnemy.update(player.m_position, player.m_velocity);
	wanderEnemy.update(player.m_position, player.m_velocity);
	fleeEnemy.update(player.m_position, player.m_velocity);
	arriveEnemySlow.update(player.m_position, player.m_velocity);
	arriveEnemyFast.update(player.m_position, player.m_velocity);
	seekEnemy.avoid(enemyPos);
	fleeEnemy.avoid(enemyPos);
	wanderEnemy.avoid(enemyPos);
	arriveEnemySlow.avoid(enemyPos);
	arriveEnemyFast.avoid(enemyPos);
}

void Game::render() {
	m_window.clear();
	player.render(m_window);
	wanderEnemy.render(m_window);
	seekEnemy.render(m_window);
	fleeEnemy.render(m_window);
	arriveEnemySlow.render(m_window);
	arriveEnemyFast.render(m_window);
	m_window.display();
	
}