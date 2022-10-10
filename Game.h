#ifndef game_h
#define game_h

#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Player.h"
#include "Tree.h"

class Game {
    private:
        int cursorX;
        int cursorY;

    public:
        Game();

        // getters
        int getCursorX() const;
        int getCursorY() const;

        // setters

        void setCursorX(int x);
        void setCursorY(int y);

        // display

        void displayDebugInfo(sf::RenderWindow& window, Player& player) const;
};

#endif