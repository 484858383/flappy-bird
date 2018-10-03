#include"Bird.h"

Bird::Bird()
:m_gravity(2.50f), m_velocity(0.0f), m_maxSpeed(350.0f)
{
    m_body.setSize(sf::Vector2f(32, 32));
    m_body.setPosition(64, 240); //256 - 16 due to sfml rectangles using top left
}

void Bird::draw(sf::RenderTarget& render)
{
    render.draw(m_body);
}

void Bird::bounce()
{
    m_velocity = -1800.0f;
}


void Bird::update(float dt)
{
    m_velocity += m_gravity;
    if(m_velocity >= m_maxSpeed)
        m_velocity = m_maxSpeed;

    m_body.move(0, m_velocity * dt);
}
