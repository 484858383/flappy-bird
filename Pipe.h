#ifndef PIPE_H_INCLUDED
#define PIPE_H_INCLUDED

#include<SFML/Graphics.hpp>
#include<utility>
#include<random>
#include<array>

class Bird;

class Pipe
{
public:
    Pipe(sf::Texture& textureTop, sf::Texture& textureBody);
    void draw(sf::RenderTarget& render);
    void update(float dt);
    bool handleCollision(Bird& bird);
    void handleScores(float xPos, int& score); //xPos is birds x position

    const sf::Vector2f& getPosition() const;
private:
    std::pair<sf::RectangleShape, sf::RectangleShape> m_body; //first is top, second is bottom
    std::mt19937 m_rng; //no need for a random class for such a small project

    float m_velocity;
    int m_distance;
    bool m_passed;

    sf::Texture* m_textureTop;
    sf::Texture* m_textureBody;
private:
    void texturePipe();
    std::array<sf::RectangleShape, 4> m_model;

#endif // PIPE_H_INCLUDED
