#include"Game.h"

#include<SFML/System/Clock.hpp>
#include<iostream>

Game::Game()
:m_loss(false), m_ready(false)
{
    m_window.create(sf::VideoMode(1024,512), "window", sf::Style::Close);
    m_window.setFramerateLimit(120);
}

void Game::run()
{
    float dt = 0.0f;
    while(m_window.isOpen())
    {
        sf::Clock frameTimer;

        m_window.clear();
        handleInput(dt);

        if(m_ready)
            m_bird.update(dt); //out of update function so bird can fall once player loses

        if(!m_loss && m_ready)
            update(dt);

        render();

        m_window.display();
        handleEvents();

        dt = frameTimer.getElapsedTime().asSeconds();
    }
}

void Game::update(float dt)
{
    static sf::Clock timer; //every second a new set pipes is added

    for(auto& pipe : m_pipes)
        pipe->update(dt);
    handleCollisions();

    if(timer.getElapsedTime().asSeconds() >= 1.50f)
    {
        addPipe();
        timer.restart();
    }
    deletePipes(); //this should ideally be last operation on the pipes
}

void Game::render()
{
    for(auto& pipe : m_pipes)
        pipe->draw(m_window);
   m_bird.draw(m_window);
}


void Game::handleInput(float dt)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R) && m_loss)
        reset();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !m_ready ||
       sf::Mouse::isButtonPressed(sf::Mouse::Left) && !m_ready)
    {
        m_ready = true;
        m_bird.bounce();
    }
}

void Game::handleEvents()
{
    sf::Event e;
    while(m_window.pollEvent(e))
    {
        switch(e.type)
        {
        case sf::Event::Closed:
            m_window.close();
        case sf::Event::KeyPressed:
            if(e.key.code == sf::Keyboard::Escape)
                m_window.close();
        case sf::Event::MouseButtonPressed:
            if(e.mouseButton.button == sf::Mouse::Left && !m_loss)
                m_bird.bounce();
        default:
            break;
        }
    }
    //sadly mouse input has to go here as I want to limit bounces to button clicks
    //sf::IsButtonPressed() does not account for this and having two event loops doesnt work either
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

void Game::handleCollisions()
{
    for(auto iter = m_pipes.begin(); iter != m_pipes.end(); iter++)
    {
        if((*iter)->handleCollision(m_bird))
        {
            m_loss = true;
            break;
        }
    }
    if(m_bird.getPosition().y < 0.0f || m_bird.getPosition().y >= 480.0f)
    {
        m_loss = true;
        m_bird.stop();
    }
}

void Game::reset()
{
    m_pipes.clear();
    m_loss  = false;
    m_ready = false;
    m_bird.reset();
}
