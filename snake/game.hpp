
#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "grid.hpp"
#include "snake.hpp"
#include "fruit.hpp"

struct game {
    sf::RectangleShape background;
    bool active;
    void display_menu(sf::RenderWindow &window);
    void start_game(sf::RenderWindow &window);
    void play_game();
    game();
};

#endif /* game_hpp */
