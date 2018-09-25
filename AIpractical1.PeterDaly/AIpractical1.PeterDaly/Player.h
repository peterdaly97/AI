#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include <iostream>

class Player
{
public:
	Player();

	~Player();

	void update(sf::Time dt);
	void render(sf::RenderWindow &window);

	
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Keyboard m_keys;

	sf::Vector2f m_position;
	float m_rotation;

	const double DEG_TO_RAD = 3.14159 / 180.0f;
	float m_speed;
	const float MAX_FORWARD_SPEED = 1;
	const float MAX_BACKWARD_SPEED = -0.5;

private:
	
	
};

#endif //!PLAYER_H
