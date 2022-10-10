#ifndef entity_h
#define entity_h
#pragma once

class Entity {
    private:
        float xPos;
        float yPos;
    
    public:

        float getXPos() const;
        float getYPos() const;

        void setXPos(float x);
        void setYPos(float y);
};

#endif
