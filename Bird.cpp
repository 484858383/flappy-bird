#include"Bird.h"

Bird::Bird()
:m_gravity(25.0f), m_velocity(0.0f), m_maxSpeed(550.0f)
{
    m_body.setSize(sf::Vector2f(32, 32));
    m_body.setPosition(64, 240); //256 - 16 due to sfml rectangles using top left

    m_body.setFillColor(sf::Color::Yellow);
}

void Bird::draw(sf::RenderTarget& render)
{
    render.draw(m_body);
}

void Bird::bounce()
{
    m_velocity = -750.0f;
}

void Bird::reset()
{
    m_body.setPosition(64, 240);
    stop();
}

void Bird::update(float dt)
{
    m_velocity += m_gravity;
    if(m_velocity >= m_maxSpeed)
        m_velocity = m_maxSpeed;

    if(m_body.getPosition().y < 480.0f) //dont fall off of screen
        m_body.move(0, m_velocity * dt);
}

void Bird::stop()
{
    m_velocity = 0.0f;
}

const sf::Vector2f& Bird::getPosition() const
{
    return m_body.getPosition();
}

const sf::Vector2f& Bird::getSize() const
{
    return m_body.getSize();
}
