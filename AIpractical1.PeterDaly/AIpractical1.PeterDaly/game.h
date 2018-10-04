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
	void update(sf::Time dt);
	void render();


	Player player = Player();
	Enemy wanderEnemy = Enemy(behaviour::PATROL);
	Enemy seekEnemy = Enemy(behaviour::PURSUE);
	Enemy fleeEnemy = Enemy(behaviour::EVADE);
	sf::RenderWindow m_window;

private:


};

#endif //!GAME_H
