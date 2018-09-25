#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "SFML/Graphics.hpp"
#include <iostream>

class Triangle
{
public:
	Triangle();

	~Triangle();

	void update(sf::Vector2f playerPos);
	void render(sf::RenderWindow &window);

	float getNewRotation(float rot, sf::Vector2f vel);
	void wander(sf::Vector2f playerPos);
	void seek(sf::Vector2f playerPos);
	float mag(sf::Vector2f v);

	sf::Texture m_texture;
	sf::Sprite m_sprite;
	
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	float m_rotation;

	const double DEG_TO_RAD = 3.14159 / 180.0f;
	float m_speed;
	const float MAX_FORWARD_SPEED = 0.1;
	const float MAX_ROTATION = 0.1;
	const float MAX_BACKWARD_SPEED = 0.5;

private:


};

#endif //!TRIANGLE_H
