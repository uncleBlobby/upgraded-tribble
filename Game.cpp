#include "Game.h"

extern sf::Font font;

Game::Game(){
    cursorX = 0;
    cursorY = 0;
}

int Game::getCursorX() const {
    return cursorX;
}

int Game::getCursorY() const {
    return cursorY;
}

void Game::setCursorX(int x){
    cursorX = x;
}

void Game::setCursorY(int y){
    cursorY = y;
}

void Game::addTree(){
    trees.push_back(Tree());
}

void Game::drawTrees(sf::RenderWindow& window) const {
    for (int i = 0; i < int(trees.size()); i++){
        trees[i].drawTree(window);
    }
}

void Game::displayDebugInfo(sf::RenderWindow& window, Player& player) const {
    sf::Text gameInfo;
    gameInfo.setFont(font);
    
    gameInfo.setCharacterSize(12);
    gameInfo.setFillColor(sf::Color::White);
   
    gameInfo.setPosition(0.f, 0.f);
    gameInfo.setString("Player X:");
    window.draw(gameInfo);
    
    gameInfo.setString(std::to_string(player.getXPos()));
    gameInfo.setPosition(100.f, 0.f);
    window.draw(gameInfo);

    gameInfo.setPosition(0.f, 13.f);
    gameInfo.setString("Player Y:");
    window.draw(gameInfo);

    gameInfo.setPosition(100.f, 13.f);
    gameInfo.setString(std::to_string(player.getYPos()));
    window.draw(gameInfo);

    gameInfo.setPosition(0.f, 25.f);
    gameInfo.setString("Mouse X:");
    window.draw(gameInfo);

    gameInfo.setPosition(100.f, 25.f);
    gameInfo.setString(std::to_string(getCursorX()));
    window.draw(gameInfo);

    gameInfo.setPosition(0.f, 38.f);
    gameInfo.setString("Mouse Y:");
    window.draw(gameInfo);

    gameInfo.setPosition(100.f, 38.f);
    gameInfo.setString(std::to_string(getCursorY()));
    window.draw(gameInfo);
}

void Game::checkCursorTarget() const {
    for (int i = 0; i < TREES_TO_SPAWN; i++){
        if (cursorX > trees[i].getXPos() && cursorX < (trees[i].getXPos() + trees[i].getWidth())){
            if (cursorY > trees[i].getYPos() && cursorY < (trees[i].getYPos() + trees[i].getHeight())){
                // printf("Cursor is over tree: %s\n", trees[i].getId());
                std::cout << "Cursor is over tree: " << trees[i].getID() << std::endl;
            } else {
                printf("Cursor is not over tree!\n");
            }
        }
    }
}