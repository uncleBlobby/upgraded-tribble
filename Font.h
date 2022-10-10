#ifndef font_h
#define font_h

#pragma once

#include <SFML/Graphics.hpp>

sf::Font loadFont(){
    sf::Font font;
    font.loadFromFile("./res/font/VeraMono.ttf");
    if(!font.loadFromFile("./res/font/VeraMono.ttf")){
        printf("Failed to load font!\n");
    }
    
    return font;

}

#endif