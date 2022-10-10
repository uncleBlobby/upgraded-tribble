#include "Player.h"

Player::Player(){
    xPos = 50.0f;
    yPos = 50.0f;
    height = 25.0f;
    width = 25.0f;

    velocity = sf::Vector2f(0.f, 0.f);
    rectangle = sf::RectangleShape(sf::Vector2f(width, height));
}

void Player::drawPlayer(sf::RenderWindow& window){
    window.draw(rectangle);
}