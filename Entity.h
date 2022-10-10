#ifndef entity_h
#define entity_h
#pragma once

#include <string>

class Entity {
    private:
        float xPos;
        float yPos;

        std::string uuid;

        std::string type;
    
    public:

        float getXPos() const;
        float getYPos() const;

        void setXPos(float x);
        void setYPos(float y);

        std::string getType() const;
        void setType(std::string s);

        std::string getID() const;
        void initID();

};

#endif
