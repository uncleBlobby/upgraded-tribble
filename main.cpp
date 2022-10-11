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
                std::cout << "Distance to target: " << player.getDistanceToEntity(game.returnCursorTargetEntity()) << std::endl;
                if (player.getDistanceToEntity(game.returnCursorTargetEntity()) <= player.getReachDistance()){
                    game.action(game.returnCursorTargetEntity());
                }
                

                //game.checkCursorTarget(window);
            }
            if (event.type == sf::Event::MouseMoved){
                game.setCursorX(event.mouseMove.x);
                game.setCursorY(event.mouseMove.y);

                game.checkCursorTarget(window);
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
        //printf("Delta Time: %f\n", delta);

        // gameupdate loop

        // render loop
        window.clear(sf::Color::Black);

        

        player.move(delta);
        player.drawPlayer(window);
        //player.displayPlayerInfo(window);

        game.drawTrees(window);
        //game.checkCursorTarget();
        
        game.drawSelector(window);

        game.displayDebugInfo(window, player, delta);


        // end the current frame
        window.display();
    }
    return 0;
}