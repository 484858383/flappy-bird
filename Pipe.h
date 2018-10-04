#ifndef PIPE_H_INCLUDED
#define PIPE_H_INCLUDED

#include<SFML/Graphics.hpp>
#include<utility>
#include<random>

class Pipe
{
public:
    Pipe();

    void draw(sf::RenderTarget& render);
    void update(float dt);

    const sf::Vector2f& getPosition() const;
private:
    std::pair<sf::RectangleShape, sf::RectangleShape> m_body; //first is top, second is bottom
    std::mt19937 m_rng; //no need for a random class for such a small project

    float m_velocity;
    int m_distance;
};

#endif // PIPE_H_INCLUDED
