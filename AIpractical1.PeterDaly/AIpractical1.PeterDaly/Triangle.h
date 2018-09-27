#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "SFML/Graphics.hpp"
#include <iostream>

class Triangle
{
public:
	Triangle();

	~Triangle();

	void update();
	void render(sf::RenderWindow &window);

	float getNewRotation(float rot, sf::Vector2f vel);
	void wander();
	void seek(sf::Vector2f playerPos);
	void flee(sf::Vector2f playerPos);
	float mag(sf::Vector2f v);
	void startCalc();
	float dist(sf::Vector2f v1, sf::Vector2f v2);
	void arrive();

	sf::Texture m_texture;
	sf::Sprite m_sprite;
	
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	float m_rotation;
	sf::Vector2f m_targetPos;

	const double DEG_TO_RAD = 3.14159 / 180.0f;
	float m_speed;
	const float MAX_FORWARD_SPEED = 0.1;
	const float MAX_ROTATION = 10;
	const float MAX_BACKWARD_SPEED = 0.5;
	const float TIME_TO_TARGET = 1.0f;

private:


};

#endif //!TRIANGLE_H
