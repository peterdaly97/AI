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

	m_targetPos.x = rand() % 2048;
	m_targetPos.y = rand() % 1080;
}



Triangle::~Triangle()
{
}

void Triangle::update()
{
	m_position += m_velocity;
	m_sprite.setPosition(m_position);
}

void Triangle::wander() {
	m_velocity = m_targetPos - m_position;
	startCalc();
	m_rotation = m_rotation + (MAX_ROTATION * ((rand() % 1) - 1));
	m_sprite.setRotation(m_rotation);
	
	m_velocity = sf::Vector2f(-std::sin(m_rotation), std::cos(m_rotation));
	m_velocity *= MAX_FORWARD_SPEED;

	if (dist(m_targetPos, m_position) < 10) {
		m_targetPos.x = rand() % 2048;
		m_targetPos.y = rand() % 1080;
	}
}

void Triangle::flee(sf::Vector2f playerPos) {
	m_velocity = m_position - playerPos;
	startCalc();
	m_sprite.setRotation(m_rotation);

	m_position = sf::Vector2f(m_position.x + std::cos(DEG_TO_RAD  * (m_rotation)) * m_speed,
		m_position.y + std::sin(DEG_TO_RAD * (m_rotation)) * m_speed);
}

void Triangle::seek(sf::Vector2f playerPos) {
	m_velocity = playerPos - m_position;
	startCalc();
	m_sprite.setRotation(m_rotation);

	m_position = sf::Vector2f(m_position.x + std::cos(DEG_TO_RAD  * (m_rotation)) * m_speed,
		m_position.y + std::sin(DEG_TO_RAD * (m_rotation)) * m_speed);
}

void Triangle::arrive() {
	m_velocity = sf::Vector2f(m_velocity.x / TIME_TO_TARGET, m_velocity.y / TIME_TO_TARGET);
	if (mag(m_velocity) > MAX_FORWARD_SPEED) {
		m_velocity = sf::Vector2f(m_velocity.x / mag(m_velocity), m_velocity.y / mag(m_velocity));
		m_velocity *= MAX_FORWARD_SPEED;
	}
	m_rotation = getNewRotation(m_rotation, m_velocity);
	m_sprite.setRotation(m_rotation);
	
}

void Triangle::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

float Triangle::getNewRotation(float rot, sf::Vector2f vel)
{
	if (mag(m_velocity) > 0.0) {
		float rotation = std::atan2(-m_velocity.x, m_velocity.y) * (180 / 3.14159);
		return (rotation + 90);
	}
	else {
		return rot;
	}
	
}

float Triangle::mag(sf::Vector2f v) {
	return std::sqrt(v.x * v.x + v.y * v.y);
}

void Triangle::startCalc() {
	float magnitude = mag(m_velocity);
	m_velocity = sf::Vector2f(m_velocity.x / magnitude, m_velocity.y / magnitude);
	m_velocity = m_velocity * m_speed;
	m_rotation = getNewRotation(m_rotation, m_velocity);
}

float Triangle::dist(sf::Vector2f v1, sf::Vector2f v2) {
	float dist = std::sqrt(((v1.x - v2.x) * (v1.x - v2.x)) + ((v1.y - v2.y) * (v1.y - v2.y)));
	return dist;
}
