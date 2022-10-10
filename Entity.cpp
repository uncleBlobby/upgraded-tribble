#include "Entity.h"

std::string generateUUID();


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

std::string Entity::getType() const {
    return type;
}

void Entity::setType(std::string s){
    type = s;
}

std::string Entity::getID() const {
    return uuid;
}

void Entity::initID(){
    uuid = generateUUID();
}

std::string generateUUID(){
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::string newID = "XXXX-XXXX-XXXX-XXXX";
    //unsigned seed = time(NULL);
    //srand(seed);
    for (int i = 0; i < 19; i++){
        if(newID[i] != '-'){
            newID[i] = letters[rand()%62];
        }
        
    }
    return newID;
}