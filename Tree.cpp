#include <time.h>
#include "Tree.h"
#include "Game.h"

Tree::Tree(){
    setXPos(rand() % WINDOW_WIDTH);
    setYPos(rand() % WINDOW_HEIGHT); 
    height = rand() % 50 + 25;
    width = 10;

    id = "tree"+ (std::to_string(rand() % 10000));

    rectangle = sf::RectangleShape(sf::Vector2f(width, height));
    circle = sf::CircleShape(15.f);

    rectangle.setPosition(getXPos(), getYPos());
    rectangle.setFillColor(sf::Color(139, 69, 19));

    circle.setPosition(getXPos() - width, getYPos());
    circle.setFillColor(sf::Color(34, 139, 34));
}

int Tree::getHeight() const {
    return height;
}

int Tree::getWidth() const {
    return width;
}

std::string Tree::getId() const {
    return id;
}

void Tree::drawTree(sf::RenderWindow& window) const {
    window.draw(rectangle);
    window.draw(circle);
}