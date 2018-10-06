#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include<SFML/Graphics.hpp>
#include<memory>

#include"Bird.h"
#include"Pipe.h"

#include<SFML/Graphics.hpp>
#include<memory>

#include"Bird.h"
#include"Pipe.h"

class Game
{
public:
    Game();

    void run();
private:
    sf::RenderWindow m_window;
    std::vector<std::unique_ptr<Pipe>> m_pipes;

    sf::Font m_font;
    sf::Text m_scoreText;
    sf::Text m_lossMessage;
    sf::Text m_startMessage;

    Bird m_bird;
    bool m_loss;
    bool m_ready;
    int  m_score;
private:
    void handleInput(float dt);
    void handleEvents();
    void update(float dt);
    void render();

    void addPipe();
    void deletePipes();
    void handleCollisions();
    void handleScoring();
    void reset();
};

#endif // GAME_H_INCLUDED
