#include "Player.h"

int main(){
    printf("Hello, SFML2!\n");

    sf::RenderWindow window(sf::VideoMode(1920/2, 1080/2), "SFML Game");
    window.setFramerateLimit(60);

    Player player;

    while (window.isOpen()){

        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        // gameupdate loop

        // render loop
        window.clear(sf::Color::Black);

        player.drawPlayer(window);


        // end the current frame
        window.display();
    }
    return 0;
}