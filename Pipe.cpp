#include"Pipe.h"

#include"Bird.h"

namespace
{
    sf::Vector2f& abs(sf::Vector2f&& vec)
    {
        if(vec.x < 0.0f)
            vec.x = std::abs(vec.x);

        if(vec.y < 0.0f)
            vec.y = std::abs(vec.y);
        return vec;
    }
}

Pipe::Pipe()
:m_rng(std::time(nullptr)), m_velocity(-250.0f), m_distance(128), m_passed(false)
{
    std::uniform_int_distribution<int> dist(32, 352);
    int topHeight = dist(m_rng);

    sf::RectangleShape top(sf::Vector2f(48, topHeight));
    top.setPosition(1280, 0);
    top.setFillColor(sf::Color::Green);
    m_body.first = top;

    int bottomHeight = 512 - (topHeight + m_distance);

    sf::RectangleShape bottom(sf::Vector2f(48, bottomHeight));
    bottom.setPosition(1280, topHeight + m_distance);
    bottom.setFillColor(sf::Color::Green);
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

bool Pipe::handleCollision(Bird& bird)
{
    auto birdPos    = bird.getPosition() + (bird.getSize() / 2.0f);
    auto thisPosTop = m_body.first.getPosition()  + (m_body.first.getSize() / 2.0f);
    auto thisPosBot = m_body.second.getPosition() + (m_body.second.getSize() / 2.0f);

    auto birdHalfSize    = bird.getSize() / 2.0f;
    auto thisHalfSizeTop = m_body.first.getSize() / 2.0f;
    auto thisHalfSizeBot = m_body.second.getSize() / 2.0f;

    sf::Vector2f deltaTop = abs(birdPos - thisPosTop) - (thisHalfSizeTop + birdHalfSize);
    sf::Vector2f deltaBot = abs(birdPos - thisPosBot) - (thisHalfSizeBot + birdHalfSize);

    if((deltaTop.x <= 0.0f && deltaTop.y <= 0.0f) ||
       (deltaBot.x <= 0.0f && deltaBot.y <= 0.0f))
    {
        return true;
    }
    return false;
}

void Pipe::handleScores(float xPos, int& score)
{
    float thisX = m_body.first.getPosition().x + (m_body.first.getSize().x / 2.0f);
    if(xPos > thisX && !m_passed)
    {
        score++;
        m_passed = true;
    }

}

const sf::Vector2f& Pipe::getPosition() const
{
    return m_body.first.getPosition();
}
