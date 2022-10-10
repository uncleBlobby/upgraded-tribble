#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <stdio.h>

const float MAX_SPEED = 2.f;

class Player {
    private:
        float xPos;
        float yPos;
        float height;
        float width;

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

        // setters

        void setXPos(float x);
        void setYPos(float y);
        void setHeight(float h);
        void setWidth(float w);

        void setVelocity(sf::Vector2f v);
        void setXVelocity(float velX);
        void setYVelocity(float velY);

        // utility

        void move(float delta);
        void stop(char axis);

        // draw

        void drawPlayer(sf::RenderWindow& window);
};
