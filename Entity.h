#ifndef entity_h
#define entity_h
#pragma once

#include <string>

class Entity {
    private:
        float xPos;
        float yPos;

        std::string uuid;
    
    public:

        float getXPos() const;
        float getYPos() const;

        void setXPos(float x);
        void setYPos(float y);

        std::string getID() const;
        void initID();

};

#endif
