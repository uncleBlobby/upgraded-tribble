#include "Entity.h"


float Entity::getXPos() const {
    return xPos;
}

float Entity::getYPos() const {
    return yPos;
}

void Entity::setXPos(float x){
    xPos = x;
}

void Entity::setYPos(float y){
    yPos = y;
}
