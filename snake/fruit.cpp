
#include "fruit.hpp"

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <deque>

fruit::fruit() {
    this->fruit_block.setSize(sf::Vector2f(30,30));
    this->fruit_block.setFillColor(sf::Color::Green);
    this->active = false; 
}

void fruit::spawn_fruit(std::deque<sf::Vector2f> coords, sf::RenderWindow &window) {
    bool result {false};
    while (result == false) {
    int randx = rand() % 600;
    int randy = rand() % 600;
        if (randx % 30 == 0 && randy % 30 == 0) { // Need spawn to be a multiple of 30 for X and Y coordinates
            fruit_coords.x = randx;
            fruit_coords.y = randy;
            int count {0};
            for (size_t i = 0; i < coords.size(); i++) {
               if (fruit_coords == coords[i]) {
                   count --;
               }
               else if (fruit_coords != coords[i]) {
                   count ++;
               }
            }
            if (count == coords.size()) {
                result = true;
                this->active = true; // Can spawn fruit
            }
            else if (count != coords.size()) {
                result = false; // Can't spawn fruit
            }
        }
    }
}

void fruit::draw_fruit(sf::RenderWindow &window) {
    this->fruit_block.setPosition(fruit_coords);
    window.draw(fruit_block);
}



