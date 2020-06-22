
#ifndef snake_hpp
#define snake_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

#include <deque>
#include <vector>

class snake {
private:
    int num; // num of blocks
    sf::Vector2f head_coords; // Constantly updating
    std::deque<sf::Vector2f> coords {}; // coords block will move along
    std::vector<sf::RectangleShape> block; // makes up snakes body
    std::string dir; // UP, DOWN, LEFT, RIGHT,
public:
    snake();
    void draw_snake(sf::RenderWindow &window);
    void player_input(sf::RenderWindow &window);
    void move_snake();
    bool out_of_bounds();
    std::deque<sf::Vector2f> return_coords();
    bool snake_ate(sf::Vector2f &fruit_coords, bool &fruit_active);
    bool add_block;
    bool has_collided();
    void write_score(); 
};

#endif /* snake_hpp */
