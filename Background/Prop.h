#ifndef PROP_H_INCLUDED
#define PROP_H_INCLUDED

#include<SFML/Graphics.hpp>
#include<random>

class Prop
{
public:
    Prop(sf::Texture& texture, const sf::Vector2f& size, float speed);

    void draw(sf::RenderTarget& render);
    void update(float dt);
    bool hasDeleteFlag() const;

    virtual void setRect();
protected:
    sf::RectangleShape m_body;
    sf::Texture* m_texture;
    float m_speed;
    bool m_deleteFlag;

    std::mt19937 m_rng;
};

#endif // PROP_H_INCLUDED
