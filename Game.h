#ifndef game_h
#define game_h

#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Player.h"
#include "Tree.h"

const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;

const int TREES_TO_SPAWN = 50;

class Game {
    private:
        int cursorX;
        int cursorY;

        Tree trees[TREES_TO_SPAWN];

    public:
        Game();

        // getters
        int getCursorX() const;
        int getCursorY() const;

        void getCursorTarget() const;

        // setters

        void setCursorX(int x);
        void setCursorY(int y);

        void addTree(int i);

        void drawTrees(sf::RenderWindow& window) const;

        // display

        void displayDebugInfo(sf::RenderWindow& window, Player& player) const;

        void checkCursorTarget() const;
};

#endif