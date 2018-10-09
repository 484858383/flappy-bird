#include"Building.h"

Building::Building(sf::Texture& texture)
:Prop(texture,{144, 256},  62.5f)
{
    setRect();
}

void Building::setRect()
{
    std::uniform_int_distribution<int> dist(0, 6);
    int sizeX = 9;
    int sizeY = 16;

    int r = dist(m_rng);
    int x = r * sizeX;
    int y = 0;

    m_body.setTextureRect(sf::IntRect(x, y, sizeX, sizeY));
    m_body.setPosition(1280, 256);
}
