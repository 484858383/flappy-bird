#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include<SFML/Graphics.hpp>

#include"Bird.h"

class Game
{
public:
    Game();

    void run();
    void handleInput(float dt);
    void handleEvents();
private:
    sf::RenderWindow m_window;
    Bird m_bird;
};

#endif // GAME_H_INCLUDED
