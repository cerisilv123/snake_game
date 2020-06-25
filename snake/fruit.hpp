
#ifndef fruit_hpp
#define fruit_hpp

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <deque>

class fruit {
private:
    sf::RectangleShape fruit_block;
public:
    fruit();
    bool active;
    sf::Vector2f fruit_coords;
    void spawn_fruit(std::deque<sf::Vector2f> coords, sf::RenderWindow &window);
    void draw_fruit(sf::RenderWindow &window);
};

#endif /* fruit_hpp */
