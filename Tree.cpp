#include <time.h>
#include "Tree.h"
#include "Game.h"

Tree::Tree(){
    xPos = rand() % WINDOW_WIDTH;
    yPos = rand() % WINDOW_HEIGHT;
    height = rand() % 50 + 25;
    width = 10;

    rectangle = sf::RectangleShape(sf::Vector2f(width, height));
    circle = sf::CircleShape(15.f);

    rectangle.setPosition(xPos, yPos);
    rectangle.setFillColor(sf::Color(139, 69, 19));

    circle.setPosition(xPos - width, yPos);
    circle.setFillColor(sf::Color(34, 139, 34));
}

int Tree::getXPos() const {
    return xPos;
}

int Tree::getYPos() const {
    return yPos;
}

int Tree::getHeight() const {
    return height;
}

int Tree::getWidth() const {
    return width;
}

void Tree::drawTree(sf::RenderWindow& window) const {
    window.draw(rectangle);
    window.draw(circle);
}