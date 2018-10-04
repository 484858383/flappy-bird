#include"Game.h"

#include<SFML/System/Clock.hpp>
#include<iostream>

Game::Game()
{
    m_window.create(sf::VideoMode(1024,512), "window", sf::Style::Close);
    m_window.setFramerateLimit(120);
}

void Game::run()
{
    float dt = 0.0f;
    sf::Clock timer; //every second a new set pipes is added

    while(m_window.isOpen())
    {
        sf::Clock frameTimer;

        m_window.clear();
        handleInput(dt);

        for(auto& pipe : m_pipes)
            pipe->draw(m_window);

        m_bird.draw(m_window);

        m_bird.update(dt);

        for(auto& pipe : m_pipes)
            pipe->update(dt);

        m_window.display();
        handleEvents();

        dt = frameTimer.getElapsedTime().asSeconds();

        if(timer.getElapsedTime().asSeconds() >= 1.50f)
        {
            addPipe();
            timer.restart();
        }

        deletePipes();
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
        if(e.type == sf::Event::MouseButtonPressed)
            if(e.mouseButton.button == sf::Mouse::Left)
                m_bird.bounce();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        m_window.close();
}

void Game::addPipe()
{
    m_pipes.push_back(std::make_unique<Pipe>());
}

void Game::deletePipes()
{
    for(auto iter = m_pipes.begin(); iter != m_pipes.end();)
    {
        if((*iter)->getPosition().x < -128.0f)
            iter = m_pipes.erase(iter);
        else
            iter++;
    }
}
