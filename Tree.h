#ifndef tree_h
#define tree_h

#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <stdio.h>

#include "Entity.h"

class Tree: public Entity{
    private:
        int height;
        int width;

        sf::RectangleShape rectangle;
        sf::CircleShape circle;

    public:
        Tree();

        int getHeight() const;
        int getWidth() const;

        void setHeight(int h);
        void setWidth(int w);

        void drawTree(sf::RenderWindow &window) const;
};

#endif