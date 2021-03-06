
#include <iostream>
#include <fstream>

#include "snake.hpp"
#include "fruit.hpp"
#include "game.hpp"

snake::snake() {
    this->add_block = false; 
    this->num = 3;
    this->coords.push_back(sf::Vector2f(300,300));
    this->coords.push_back(sf::Vector2f(330,300));
    this->coords.push_back(sf::Vector2f(360,300));
    this->dir = "UP";
    this->head_coords = sf::Vector2f(300,300);
    for (size_t i = 0; i < 200; i++) {
        sf::RectangleShape blocks;
        blocks.setSize(sf::Vector2f(30,30));
        blocks.setFillColor(sf::Color::Red);
        block.push_back(blocks);
    }
}

void snake::draw_snake(sf::RenderWindow &window) {
    for (size_t i = 0; i < this->num; i++) {
        block[i].setPosition(coords[i]);
        window.draw(block[i]);
    }
}

void snake::player_input(sf::RenderWindow &window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        this->dir = "LEFT";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        this->dir = "RIGHT";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        this->dir = "UP";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        this->dir = "DOWN";
    }
}

void snake::move_snake() {
    if (this->dir == "LEFT") {
        if (add_block == true) { // If snake has eaten = dont pop off the back
            head_coords.x -= 30;
            coords.push_front(head_coords);
            num++; // increase number of blocks
            add_block = false; // set boolean back to false until snake has eaten again
        }
        if (add_block == false) {
        head_coords.x -= 30;
            coords.push_front(head_coords);
            coords.pop_back();
        }
    }
    if (this->dir == "RIGHT") {
        if (add_block == true) {
            head_coords.x += 30;
            coords.push_front(head_coords);
            num++;
            add_block = false;
        }
        if (add_block == false) {
            head_coords.x += 30;
            coords.push_front(head_coords);
            coords.pop_back();
        }
    }
    if (this->dir == "UP") {
         if (add_block == true) {
            head_coords.y -= 30;
            coords.push_front(head_coords);
            num++;
            add_block = false;
         }
         if (add_block == false) {
            head_coords.y -= 30;
            coords.push_front(head_coords);
            coords.pop_back();
         }
    }
    if (this->dir == "DOWN") {
        if (add_block == true) {
            head_coords.y += 30;
            coords.push_front(head_coords);
            num++;
            add_block = false;
        }
        if (add_block == false) {
            head_coords.y += 30;
            coords.push_front(head_coords);
            coords.pop_back();
        }
    }
}

std::deque<sf::Vector2f> snake::return_coords() { // Return snakes coordinates - to be used in other class methods
    return coords; 
}

bool snake::snake_ate(sf::Vector2f &fruit_coords, bool &fruit_active) {
    bool result = false; 
    if (this->head_coords == fruit_coords) {
        result = true;
        fruit_active = false;
        add_block = true; // move snake function now knows not to pop off the back and to increase num by 1
    }
    return result;
}

bool snake::out_of_bounds() { // Check is snake is snake has left the screen
    bool result = false;
    if (head_coords.x <= -30 || head_coords.y <= -30) {
        result = true;
    }
    if (head_coords.x >= 600 || head_coords.y >= 600) {
        result = true;
    }
    for (size_t i = 1; i < num; i++) {
       if (head_coords.x == coords[i].x && head_coords.y == coords[i].y) {
            result = true;
       }
    }
    return result;
}

bool snake::has_collided() { // Check if snake has collided with itself
    bool result = false;
    int count = 0;
        for (size_t j = 1; j < num; j++) {
            if (head_coords == coords [j]) {
                count++;
            }
        }
    if (count == 2) {
        result = true; 
    }
    return result;
}

