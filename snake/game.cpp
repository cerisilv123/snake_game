
#include "game.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

game::game() {
    this->active = false;
    this->background.setSize(sf::Vector2f(600,600));
    this->background.setPosition(sf::Vector2f(0,0));
    this->background.setFillColor(sf::Color::Black);
}

void game::display_menu(sf::RenderWindow &window) {
    window.draw(this->background);
    
    sf::Font font;
    if (!font.loadFromFile("snake_font.ttf")) {
        std::cerr << "Error loading font" << std::endl;
        window.close();
    }
    sf::Text text; // Header
    text.setFont(font);
    text.setString("Snake");
    text.setCharacterSize(200);
    text.setFillColor(sf::Color::Green);
    text.setPosition(sf::Vector2f(300,300));
    sf::FloatRect width = text.getLocalBounds();
    text.setOrigin(width.width / 2, width.width / 2);
    
    sf::Text spacebar;
    spacebar.setFont(font);
    spacebar.setString("Press Spacebar to Start!");
    spacebar.setCharacterSize(50);
    spacebar.setFillColor(sf::Color::White);
    spacebar.setOutlineColor(sf::Color::Green);
    spacebar.setPosition(sf::Vector2f(300,520));
    sf::FloatRect width2 = spacebar.getLocalBounds();
    spacebar.setOrigin(width2.width / 2, width2.width / 2);
    
    window.draw(text);
    window.draw(spacebar); 
}

void game::start_game(sf::RenderWindow &window) {
        while (this->active == false) {
        sf::Event event;
           while (window.pollEvent(event)) {
              if (event.type == sf::Event::Closed) {
                    this->active = true;
                    window.close();
              }
           }
        this->display_menu(window);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            this->active = true; 
        }
        window.display(); 
    }
}

void game::play_game() {
    sf::RenderWindow window (sf::VideoMode(600, 600), "Snake Game");
    
    sf::Clock clock;
    float min_time = 0.12;
              
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
           
           this->start_game(window);
           
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
                        min_time -= 0.002;
                    }
                    fruit.draw_fruit(window);
           
                    window.display();
                    clock.restart();
                 }
//                 else if (snake.out_of_bounds() == true || snake.has_collided() == true) {
//                     this->active = false;
//                     this->play_game();
//                 }
             }
       }
}