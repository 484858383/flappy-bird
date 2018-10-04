#include"Pipe.h"

Pipe::Pipe()
:m_rng(std::time(nullptr)), m_velocity(-250.0f), m_distance(128)
{
    std::uniform_int_distribution<int> dist(32, 352);
    int topHeight = dist(m_rng);

    sf::RectangleShape top(sf::Vector2f(48, topHeight));
    top.setPosition(1280, 0);
    m_body.first = top;

    int bottomHeight = 512 - (topHeight + m_distance);

    sf::RectangleShape bottom(sf::Vector2f(48, bottomHeight));
    bottom.setPosition(1280, topHeight + m_distance);
    m_body.second = bottom;
}

void Pipe::draw(sf::RenderTarget& render)
{
    render.draw(m_body.first);
    render.draw(m_body.second);
}

void Pipe::update(float dt)
{
    m_body.first.move(dt * m_velocity, 0);
    m_body.second.move(dt * m_velocity, 0);
}

const sf::Vector2f& Pipe::getPosition() const
{
    return m_body.first.getPosition();
}
