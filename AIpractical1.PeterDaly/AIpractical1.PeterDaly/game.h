#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Triangle.h"

class Game
{
public:
	Game();

	~Game();

	void run();
	void update(sf::Time dt);
	void render();


	Player player = Player();
	Triangle tri = Triangle();
	sf::RenderWindow m_window;

private:


};

#endif //!GAME_H
