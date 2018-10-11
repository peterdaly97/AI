#include "Player.h"

Player::Player()
{
	m_texture.loadFromFile("ship.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(1000, 400);
	m_sprite.setScale(0.5, 0.5);
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);

	m_position = sf::Vector2f(1900, 1000);
	m_velocity = sf::Vector2f(0, 0);
	m_sprite.setPosition(m_position);
	m_rotation = 0;
	m_speed = 0;
}



Player::~Player()
{
}

void Player::update()
{
	if (m_keys.isKeyPressed(sf::Keyboard::Up))
	{
		if(m_speed < MAX_FORWARD_SPEED)
			m_speed += 0.15;
	}
	if (m_keys.isKeyPressed(sf::Keyboard::Down))
	{
		if(m_speed < MAX_BACKWARD_SPEED)
			m_speed -= 0.15;
	}
	if (m_keys.isKeyPressed(sf::Keyboard::Left))
	{
		m_rotation -= 3;
	}
	if (m_keys.isKeyPressed(sf::Keyboard::Right))
	{
		m_rotation += 3;
	}
	m_sprite.setPosition(m_position);
	m_sprite.setRotation(m_rotation);
	m_velocity = sf::Vector2f(std::cos(DEG_TO_RAD  * (m_rotation)) * m_speed,
		std::sin(DEG_TO_RAD * (m_rotation)) * m_speed);
	m_position += m_velocity;
	
	m_speed *= 0.999;

	if (m_position.y > 2160) {
		m_position.y = 0 - (m_sprite.getLocalBounds().height * 0.5);
	}
	else if (m_position.x > 3840) {
		m_position.x = 0 - (m_sprite.getLocalBounds().width * 0.5);
	}
	else if (m_position.y < -200) {
		m_position.y = 1080 + (m_sprite.getLocalBounds().height * 0.5);
	}
	else if (m_position.x < -200) {
		m_position.x = 2048 + (m_sprite.getLocalBounds().width * 0.5);
	}
}

void Player::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}