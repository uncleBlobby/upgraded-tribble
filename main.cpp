#include "Player.h"

int main(){
    printf("Hello, SFML2!\n");

    sf::RenderWindow window(sf::VideoMode(1920/2, 1080/2), "SFML Game");
    window.setFramerateLimit(60);

    Player player;

    sf::Clock clock;

    while (window.isOpen()){

        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::KeyPressed){
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    printf("Move player right!\n");
                    player.setXVelocity(1.f);
                }
                
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    printf("Move player left!\n");
                    player.setXVelocity(-1.f);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                    printf("Move player right!\n");
                    player.setYVelocity(-1.f);
                }
                
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                    printf("Move player left!\n");
                    player.setYVelocity(1.f);
                }

            }
            if (event.type == sf::Event::KeyReleased){
                if (event.key.code == sf::Keyboard::D){
                    player.stop('x');
                }
                if (event.key.code == sf::Keyboard::A){
                    player.stop('x');
                }
                if (event.key.code == sf::Keyboard::W){
                    player.stop('y');
                }
                if (event.key.code == sf::Keyboard::S){
                    player.stop('y');
                }
            }
            
        }
        // reset clock every frame
        sf::Time elapsed = clock.restart();
        float delta = elapsed.asSeconds();

        // gameupdate loop

        // render loop
        window.clear(sf::Color::Black);

        player.move(delta);
        player.drawPlayer(window);


        // end the current frame
        window.display();
    }
    return 0;
}