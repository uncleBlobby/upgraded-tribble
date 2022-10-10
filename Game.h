#ifndef game_h
#define game_h

#pragma once

#include <iostream>
#include <vector>
#include <string>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Player.h"
#include "Tree.h"
#include "Entity.h"
#include "Selector.h"

const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;

const int TREES_TO_SPAWN = 50;

const int MAX_ENTITIES = 500;

class Game {
    private:
        int cursorX;
        int cursorY;

        std::vector<Tree> trees;
        //Tree trees[TREES_TO_SPAWN];


        //Entity entities[MAX_ENTITIES];

        std::vector<Entity> entities;

        std::string mouseTarget;

    public:
        Game();

        // getters
        int getCursorX() const;
        int getCursorY() const;

        void getCursorTarget() const;

        std::string getMouseTarget() const;

        // setters

        void setCursorX(int x);
        void setCursorY(int y);

        void setMouseTarget(std::string s);

        void addTree();

        void drawTrees(sf::RenderWindow& window) const;

        // display

        void displayDebugInfo(sf::RenderWindow& window, Player& player) const;

        void checkCursorTarget(sf::RenderWindow& window);
};

#endif