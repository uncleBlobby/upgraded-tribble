#include "Game.h"
#include "Font.h"

sf::Font font = loadFont();

int main(){
    srand (time(NULL));
    printf("Hello, SFML2!\n");

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Game");
    window.setFramerateLimit(60);

    Game game;

    Player player;

    for (int i = 0; i < TREES_TO_SPAWN; i++){
        game.addTree();
        std::cout << "Added tree # " << i << std::endl;
    }

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
                //std::cout << "Test UUID: " << generateUUID() << std::endl;

                /*
                printf("Tree1.x: %d\n", tree.getXPos());
                printf("Tree1.y: %d\n", tree.getYPos());

                if(event.mouseButton.x > tree.getXPos() && event.mouseButton.x < (tree.getXPos() + tree.getWidth())){
                    if (event.mouseButton.y > tree.getYPos() && event.mouseButton.y < (tree.getYPos() + tree.getHeight())){
                        printf("Clicked inside tree!\n");
                    }
                }
                */

                game.checkCursorTarget(window);
            }
            if (event.type == sf::Event::MouseMoved){
                game.setCursorX(event.mouseMove.x);
                game.setCursorY(event.mouseMove.y);

                //game.checkCursorTarget(window);
                //game.checkCursorTarget();
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
        //player.displayPlayerInfo(window);

        game.drawTrees(window);
        //game.checkCursorTarget();

        game.displayDebugInfo(window, player);


        // end the current frame
        window.display();
    }
    return 0;
}