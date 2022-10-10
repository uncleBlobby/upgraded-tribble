#include <SFML/Graphics.hpp>

class Selector {
    
    private:
        float xPos;
        float yPos;

        float height;
        float width;

        sf::RectangleShape rectangle;

    public:
        Selector();

        float getXPos() const;
        float getYPos() const;

        void setXPos(float x);
        void setYPos(float y);

        float getHeight() const;
        float getWidth() const;

        void setHeight(float h);
        void setWidth(float w);

        void drawSelector(sf::RenderWindow& window) const;

};