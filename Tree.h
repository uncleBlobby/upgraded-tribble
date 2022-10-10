#ifndef tree_h
#define tree_h

#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <stdio.h>

class Tree {
    private:
        int xPos;
        int yPos;
        int height;
        int width;

        sf::RectangleShape rectangle;
        sf::CircleShape circle;

    public:
        Tree();

        int getXPos() const;
        int getYPos() const;
        int getHeight() const;
        int getWidth() const;

        void setXPos(int x);
        void setYPos(int y);
        void setHeight(int h);
        void setWidth(int w);

        void drawTree(sf::RenderWindow &window) const;
};

#endif