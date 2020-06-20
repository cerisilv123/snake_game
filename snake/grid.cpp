
#include "grid.hpp"
#include <iostream>

grid::grid() {
    this->columns = 20;
    this->rows = 20;
    square.setSize(sf::Vector2f(30, 30));
    square.setOrigin(sf::Vector2f()); // Keeping at default origin (left Corner)
    square.setFillColor(sf::Color::Black);
    square.setOutlineColor(sf::Color::White);
    square.setOutlineThickness(2);
}

void grid::draw_grid(sf::RenderWindow &window) {
    for (size_t i = 0; i < columns; i++) {
        for (size_t j = 0; j < rows; j++) {
            square.setPosition(sf::Vector2f(i * 30, j * 30));
            window.draw(square);
        }
    }
}
