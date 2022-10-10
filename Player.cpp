#include "Player.h"

Player::Player(){
    xPos = 50.0f;
    yPos = 50.0f;
    height = 25.0f;
    width = 25.0f;

    velocity = sf::Vector2f(0.f, 0.f);
    rectangle = sf::RectangleShape(sf::Vector2f(width, height));
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
    
    rectangle.move(velocity.x, velocity.y);
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

void Player::drawPlayer(sf::RenderWindow& window){
    window.draw(rectangle);
}