#include <time.h>
#include "Tree.h"

Tree::Tree(){
    xPos = rand() % 500;
    yPos = rand() % 500;
    height = rand() % 50 + 25;
    width = 10;

    rectangle = sf::RectangleShape(sf::Vector2f(width, height));

    rectangle.setPosition(xPos, yPos);
    rectangle.setFillColor(sf::Color(139, 69, 19));
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
}