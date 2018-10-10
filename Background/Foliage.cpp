#include"Foliage.h"

Foliage::Foliage(sf::Texture& texture)
:Prop(texture,{176, 128}, 200.0f)
{
    setRect();
}

void Foliage::setRect()
{
    std::uniform_int_distribution<int> dist(0, 1);
    int sizeX = 22;
    int sizeY = 16;

    int r = dist(m_rng);
    int x = r * sizeX;
    int y = 0;

    m_body.setTextureRect(sf::IntRect(x, y, sizeX, sizeY));
    m_body.setPosition(1280, 384);
}
