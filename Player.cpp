#include "Game.h"
#include "Player.h"
#include "Entity.h"

#include <iostream>
#include <cstdlib>
#include <cmath>

Player::Player(){
    xPos = 0.0f;
    yPos = 0.0f;
    height = 25.0f;
    width = 25.0f;

    velocity = sf::Vector2f(0.f, 0.f);
    rectangle = sf::RectangleShape(sf::Vector2f(width, height));

    rectangle.setPosition(xPos, yPos);
}

float Player::getXPos() const {
    return xPos;
}

float Player::getYPos() const {
    return yPos;
}

float Player::getDistanceToEntity(Entity e) const {
    float distanceX = abs(xPos - e.getXPos());
    float distanceY = abs(yPos - e.getYPos());
    return distanceX + distanceY;
}

void Player::setXVelocity(float velX){
    if (velocity.x <= MAX_SPEED && velocity.x >= -MAX_SPEED){
        velocity.x += velX;
    }
}

void Player::setYVelocity(float velY){
    if (velocity.y <= MAX_SPEED && velocity.y >= -MAX_SPEED){
        velocity.y += velY;
    }
}

void Player::move(float delta){
    //printf("Player velocity X: %f\n", velocity.x);
    
    xPos += (velocity.x * delta);
    yPos += (velocity.y * delta);
    
    rectangle.setPosition(xPos, yPos);
    //rectangle.move(velocity.x, velocity.y);
}

void Player::stop(char axis){
    //printf("Stopping player.\n");
    switch(axis){
        case 'x':
            velocity.x = 0.f;
            break;
        case 'y':
            velocity.y = 0.f;
            break;
        default:
            break;
    }

}

void Player::drawPlayer(sf::RenderWindow& window) const {
    window.draw(rectangle);
}

void Player::action(Entity e) {
    std::cout << "Player acting on entity: " << e.getID() << std::endl;
    if (e.getType() == "tree"){
        std::cout << "entity is a tree." << std::endl;
        
    }
}

/*
void Player::displayPlayerInfo(sf::RenderWindow& window) const {
    sf::Text playerInfo;
    playerInfo.setFont(font);
    
    playerInfo.setCharacterSize(12);
    playerInfo.setFillColor(sf::Color::White);
   
    playerInfo.setPosition(0.f, 0.f);
    playerInfo.setString("Player X:");
    window.draw(playerInfo);
    
    playerInfo.setString(std::to_string(getXPos()));
    playerInfo.setPosition(100.f, 0.f);
    window.draw(playerInfo);

    playerInfo.setPosition(0.f, 13.f);
    playerInfo.setString("Player Y:");
    window.draw(playerInfo);

    playerInfo.setPosition(100.f, 13.f);
    playerInfo.setString(std::to_string(getYPos()));
    window.draw(playerInfo);
}
*/