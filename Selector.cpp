#include "Selector.h"

Selector::Selector(){
    xPos = 0;
    yPos = 0;

    height = 100;
    width = 100;

    rectangle = sf::RectangleShape(sf::Vector2f(width, height));
    rectangle.setPosition(getXPos(), getYPos());
    rectangle.setFillColor(sf::Color::White);
}

void Selector::setXPos(float x){
    xPos = x;
}

void Selector::setYPos(float y){
    yPos = y;
}

float Selector::getXPos() const {
    return xPos;
}

float Selector::getYPos() const {
    return yPos;
}

void Selector::drawSelector(sf::RenderWindow& window) const {
    window.draw(rectangle);
}