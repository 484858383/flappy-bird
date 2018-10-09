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
    void reset();
    void stop();

    const sf::Vector2f& getPosition() const;
    const sf::Vector2f& getSize() const;
private:
    sf::RectangleShape m_body;
    sf::Texture m_texture;

    float m_gravity;
    float m_velocity;
    float m_maxSpeed;
};


#endif // BIRD_H_INCLUDED
