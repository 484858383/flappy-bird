#ifndef BIRD_H_INCLUDED
#define BIRD_H_INCLUDED

#include<SFML/Graphics.hpp>

class Bird
{
public:
    Bird();

    void draw(sf::RenderTarget& render);
    void update(float dt);
    void bounce();
private:
    sf::RectangleShape m_body;

    float m_gravity;
    float m_velocity;
    float m_maxSpeed;
};

#endif // BIRD_H_INCLUDED
