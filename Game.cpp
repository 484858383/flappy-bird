#include"Game.h"

#include<SFML/System/Clock.hpp>

Game::Game()
{
    m_window.create(sf::VideoMode(1024,512),"window", sf::Style::Close);
}

void Game::run()
{
    float dt = 0.0f;
    while(m_window.isOpen())
    {
        sf::Clock c;

        m_window.clear();
        handleInput(dt);

        m_bird.update(dt);
        m_bird.draw(m_window);

        m_window.display();
        handleEvents();

        dt = c.getElapsedTime().asSeconds();
    }
}

void Game::handleInput(float dt)
{
    sf::Event e;
    while(m_window.pollEvent(e))
    {
        if(e.type == sf::Event::MouseButtonPressed)
        if(e.mouseButton.button == sf::Mouse::Left)
            m_bird.bounce();
    }
}

void Game::handleEvents()
{
    sf::Event e;
    while(m_window.pollEvent(e))
    {
        if(e.type == sf::Event::Closed)
            m_window.close();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            m_window.close();
        if(e.type == sf::Event::MouseButtonPressed)
            if(e.mouseButton.button == sf::Mouse::Left)
                m_bird.bounce();
    }
}
