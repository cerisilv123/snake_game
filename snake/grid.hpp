
#ifndef grid_hpp
#define grid_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

// ===== CLASS TO CREATE AND DISPLAY A GRID TO THE SCREEN ===== //

class grid {
private:
    int columns;
    int rows;
    sf::RectangleShape square;
public:
    grid();
    void draw_grid(sf::RenderWindow &window);
};


#endif /* grid_hpp */
