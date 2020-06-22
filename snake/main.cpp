
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "grid.hpp"
#include "snake.hpp"
#include "fruit.hpp"
#include "game.hpp"

int main() {
    game game;
    
    sf::Music music;
    if (!music.openFromFile("relax-song.wav")) {
        std::cout << "Error playing music" << std::endl;
    }
    music.play();
    
    game.play_game();
}
