#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Enemy.h"

class Game
{
public:
	Game();

	~Game();

	void run();
	void update();
	void render();


	Player player = Player();
	Enemy wanderEnemy = Enemy(behaviour::PATROL);
	Enemy seekEnemy = Enemy(behaviour::PURSUE);
	Enemy fleeEnemy = Enemy(behaviour::EVADE);
	Enemy arriveEnemySlow = Enemy(behaviour::ARRIVE);
	Enemy arriveEnemyFast = Enemy(behaviour::ARRIVE);
	sf::RenderWindow m_window;

private:
	std::vector<sf::Vector2f *> enemyPos;
};

#endif //!GAME_H
