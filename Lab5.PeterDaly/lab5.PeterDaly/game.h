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
	sf::RenderWindow m_window;

private:
	std::vector<Enemy *> enemies;
	std::vector<sf::Vector2f *> enemyPos;
};

#endif //!GAME_H
