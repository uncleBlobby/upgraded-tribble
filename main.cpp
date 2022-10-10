#include "Player.h"
#include "Tree.h"

int main(){
    srand (time(NULL));
    printf("Hello, SFML2!\n");

    sf::RenderWindow window(sf::VideoMode(1920/2, 1080/2), "SFML Game");
    window.setFramerateLimit(60);

    Player player;

    Tree tree;
    Tree tree2;

    sf::Clock clock;

    while (window.isOpen()){

        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed){
                printf("Mouse button clicked!\n");
                printf("Mouse x: %d\n", event.mouseButton.x);
                printf("Mouse y: %d\n", event.mouseButton.y);

                printf("Tree1.x: %d\n", tree.getXPos());
                printf("Tree1.y: %d\n", tree.getYPos());

                if(event.mouseButton.x > tree.getXPos() && event.mouseButton.x < (tree.getXPos() + tree.getWidth())){
                    if (event.mouseButton.y > tree.getYPos() && event.mouseButton.y < (tree.getYPos() + tree.getHeight())){
                        printf("Clicked inside tree!\n");
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed){
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    //printf("Move player right!\n");
                    player.setXVelocity(ACCELERATION);
                }
                
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    //printf("Move player left!\n");
                    player.setXVelocity(-ACCELERATION);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                    //printf("Move player right!\n");
                    player.setYVelocity(-ACCELERATION);
                }
                
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                    //printf("Move player left!\n");
                    player.setYVelocity(ACCELERATION);
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
        player.displayPlayerInfo(window);

        tree.drawTree(window);
        tree2.drawTree(window);


        // end the current frame
        window.display();
    }
    return 0;
}