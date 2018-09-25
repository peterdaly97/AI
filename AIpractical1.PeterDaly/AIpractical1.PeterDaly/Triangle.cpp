#include "Triangle.h"

Triangle::Triangle()
{
	srand(time(0));
	m_texture.loadFromFile("alien.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(1000, 400);
	m_sprite.setScale(0.05, 0.05);
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);

	m_speed = 0.1;
	m_position = sf::Vector2f(50, 400);
	m_velocity = sf::Vector2f(0, 0);
	m_sprite.setPosition(m_position);
	m_rotation = 0;
}



Triangle::~Triangle()
{
}

void Triangle::update(sf::Vector2f playerPos)
{
	seek(playerPos);
}

void Triangle::wander(sf::Vector2f playerPos) {
	m_velocity = playerPos - m_position;
	float magnitude = mag(m_velocity);
	m_velocity = sf::Vector2f(m_velocity.x / magnitude, m_velocity.y / magnitude);
	m_velocity = m_velocity * m_speed;
	m_rotation = getNewRotation(m_rotation, m_velocity);
	m_rotation = m_rotation + (MAX_ROTATION * ((rand() % 1) - 1));
	m_sprite.setRotation(m_rotation);
	
	m_position += m_velocity;
	m_sprite.setPosition(m_position);
}

void Triangle::seek(sf::Vector2f playerPos) {
	m_velocity = playerPos - m_position;
	float magnitude = mag(m_velocity);
	m_velocity = sf::Vector2f(m_velocity.x / magnitude, m_velocity.y / magnitude);
	m_velocity = m_velocity * m_speed;
	m_rotation = getNewRotation(m_rotation, m_velocity);
	m_sprite.setRotation(m_rotation);

	m_position = sf::Vector2f(m_position.x + std::cos(DEG_TO_RAD  * (m_rotation)) * m_speed,
		m_position.y + std::sin(DEG_TO_RAD * (m_rotation)) * m_speed);
	m_sprite.setPosition(m_position);
}

void Triangle::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

float Triangle::getNewRotation(float rot, sf::Vector2f vel)
{
	if (mag(m_velocity) > 0.0) {
		float rotation = std::atan2(-m_velocity.x, m_velocity.y) * (180 / 3.14159);
		return (rotation);
	}
	else {
		return rot;
	}
	
}

float Triangle::mag(sf::Vector2f v) {
	return std::sqrt(v.x * v.x + v.y * v.y);
}
