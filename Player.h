#ifndef player_h
#define player_h

#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Entity.h"
#include "Game.h"

#include <stdio.h>

const float MAX_SPEED = 100.f;
const float ACCELERATION = 75.f;

class Player {
    private:
        float xPos;
        float yPos;
        float height;
        float width;

        float reachDistance;

        sf::Vector2f velocity;

        sf::RectangleShape rectangle;

    public:
        // constructor
        Player();
        // getters
        float getXPos() const;
        float getYPos() const;
        float getHeight() const;
        float getWidth() const;

        sf::Vector2f getVelocity() const;
        float getXVelocity() const;
        float getYVelocity() const;

        float getReachDistance() const;

        float getDistanceToEntity(Entity e) const;

        // setters

        void setXPos(float x);
        void setYPos(float y);
        void setHeight(float h);
        void setWidth(float w);

        void setVelocity(sf::Vector2f v);
        void setXVelocity(float velX);
        void setYVelocity(float velY);

        void action(Entity e);

        // utility

        void move(float delta);
        void stop(char axis);

        // draw

        void drawPlayer(sf::RenderWindow& window) const;

        void displayPlayerInfo(sf::RenderWindow& window) const;
};

#endif