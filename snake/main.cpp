
#include <SFML/Graphics.hpp>
#include <iostream>

#include "grid.hpp"
#include "snake.hpp"
#include "fruit.hpp"

int main() {

    sf::RenderWindow window (sf::VideoMode(600, 600), "Snake Game");
    
    sf::Clock clock;
    float min_time = 0.1;
    
    grid grid;
    snake snake;
    fruit fruit;
    
    while (window.isOpen()) {
        // Handle Events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        float delta_time = clock.getElapsedTime().asSeconds(); // Get time elapsed
        
        if (delta_time > min_time) {
            if (snake.out_of_bounds() == false && snake.has_collided() == false) {
               window.clear();
        
               grid.draw_grid(window);
          
               snake.move_snake();
               snake.draw_snake(window);
               snake.player_input(window);
               snake.snake_ate(fruit.fruit_coords, fruit.active);
                
               if (fruit.active == false) {
                   fruit.spawn_fruit(snake.return_coords(), window);
                   min_time -= 0.001;
               }
               fruit.draw_fruit(window);
        
               window.display();
               clock.restart();
            }
            else {
                
            }
        }
    }
}
