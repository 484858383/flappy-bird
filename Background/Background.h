#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

#include<SFML/Graphics.hpp>
#include<SFML/System/Clock.hpp>
#include<vector>
#include<memory>

#include"Building.h"
#include"Foliage.h"

class Background
{
public:
    Background();

    void drawForeground(sf::RenderTarget& render);
    void drawBackground(sf::RenderTarget& render);
    void update(float dt);

    void reset();
private:
    sf::Texture m_sky;
    sf::Texture m_buildingTexture;
    sf::Texture m_foliageTexture;

    sf::RectangleShape m_bgStatic; //the sky wont move
    std::vector<std::unique_ptr<Building>> m_bg; //background
    std::vector<std::unique_ptr<Foliage>> m_fg; //foreground
private:
    void addBuilding();
    void addFoliage();

    void deleteProps();
};

#endif // BACKGROUND_H_INCLUDED
