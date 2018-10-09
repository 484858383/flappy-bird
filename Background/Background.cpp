#include"Background.h"

Background::Background()
:m_bgStatic({1024, 512})
{
    m_sky.loadFromFile("res/bg0.png");
    m_buildingTexture.loadFromFile("res/bg1.png");
    m_foliageTexture.loadFromFile("res/bg2.png");

    m_bgStatic.setTexture(&m_sky);
    addBuilding();
    addFoliage();
}

void Background::drawForeground(sf::RenderTarget& render)
{
    for(auto& foliage : m_fg)
        foliage->draw(render);
}

void Background::drawBackground(sf::RenderTarget& render)
{
    render.draw(m_bgStatic);
    for(auto& building : m_bg)
        building->draw(render);
}

void Background::update(float dt)
{
    static sf::Clock ftimer;
    static sf::Clock btimer;

    for(auto& building : m_bg)
        building->update(dt);

    for(auto& foliage : m_fg)
        foliage->update(dt);

    if(btimer.getElapsedTime().asSeconds() >= 2.5f)
    {
        addBuilding();
        btimer.restart();
    }
    if(ftimer.getElapsedTime().asSeconds() >= 0.9f)
    {
        addFoliage();
        ftimer.restart();
    }

    deleteProps();
}

void Background::addBuilding()
{
    m_bg.push_back(std::make_unique<Building>(m_buildingTexture));
}

void Background::addFoliage()
{
    m_fg.push_back(std::make_unique<Foliage>(m_foliageTexture));
}

void Background::deleteProps()
{
    for(auto iter = m_bg.begin(); iter != m_bg.end();)
    {
        if((*iter)->hasDeleteFlag())
            iter = m_bg.erase(iter);
        else
        {
            iter++;
        }
    }
    for(auto iter = m_fg.begin(); iter != m_fg.end();)
    {
        if((*iter)->hasDeleteFlag())
            iter = m_fg.erase(iter);
        else
        {
            iter++;
        }
    }
}

void Background::reset()
{
    m_bg.clear();
    m_fg.clear();
}


