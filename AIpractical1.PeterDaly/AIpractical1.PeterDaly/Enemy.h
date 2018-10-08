#ifndef ENEMY_H
#define ENEMY_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "Player.h"

enum behaviour
{
	PURSUE,
	EVADE,
	PATROL
};

class Enemy
{
public:
	Enemy(behaviour behaviour);

	~Enemy();

	void update(sf::Vector2f playerPos, sf::Vector2f playerVel);
	void render(sf::RenderWindow &window);

	float getNewRotation(float rot, sf::Vector2f vel);
	void wander();
	void seek(sf::Vector2f playerPos);
	void flee(sf::Vector2f playerPos);
	float mag(sf::Vector2f v);
	void startCalc();
	float dist(sf::Vector2f v1, sf::Vector2f v2);
	void arrive(sf::Vector2f playerPos);
	bool avoid(sf::FloatRect player);

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	float m_rotation;
	sf::Vector2f m_targetPos;

	const double DEG_TO_RAD = 3.14159 / 180.0f;
	float m_speed;
	const float MAX_FORWARD_SPEED = 5;
	const float MAX_ROTATION = 1;
	const float MAX_BACKWARD_SPEED = 5;
	const float TIME_TO_TARGET = 80.0f;

private:
	behaviour b;
	sf::Text m_text;
	sf::Font m_font;
	sf::CircleShape triangle;
	float m_deviation;
};

#endif //!Enemy_H

