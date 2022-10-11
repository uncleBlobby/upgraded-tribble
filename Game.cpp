#include "Game.h"

#include <typeinfo>

extern sf::Font font;

Game::Game(){
    cursorX = 0;
    cursorY = 0;

    mouseTarget = "";
}

int Game::getCursorX() const {
    return cursorX;
}

int Game::getCursorY() const {
    return cursorY;
}

std::string Game::getMouseTarget() const {
    return mouseTarget;
}

Selector Game::getSelector() const {
    return selector;
}

void Game::setCursorX(int x){
    cursorX = x;
}

void Game::setCursorY(int y){
    cursorY = y;
}

void Game::setMouseTarget(std::string s){
    mouseTarget = s;
}

void Game::setSelector(Selector s){
    selector = s;
}

void Game::addTree(){
    trees.push_back(Tree());
}

void Game::drawTrees(sf::RenderWindow& window) const {
    for (int i = 0; i < int(trees.size()); i++){
            trees[i].drawTree(window);       
    }
}

Tree Game::getTreeAtIndex(int i) {
    return trees[i];
}

int Game::getTreesLength() const {
    return trees.size();
}

void Game::action(Entity e) {
    std::cout << "Player acting on entity: " << e.getID() << std::endl;
    if (e.getType() == "tree"){
        std::cout << "entity is a tree." << std::endl;
        for (int i = 0; i < int(trees.size()); i++){
            if (e.getID() == trees[i].getID()){
                trees.erase(trees.begin()+i);
            }
        }
        
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

    gameInfo.setPosition(0.f, 50.f);
    gameInfo.setString("Mouse Target:");
    window.draw(gameInfo);

    gameInfo.setPosition(100.f, 50.f);
    gameInfo.setString(getMouseTarget());
    window.draw(gameInfo);
}

void Game::checkCursorTarget(sf::RenderWindow& window){
    for (int i = 0; i < TREES_TO_SPAWN; i++){
        if (cursorX > trees[i].getXPos() && cursorX < (trees[i].getXPos() + trees[i].getWidth())){
            if (cursorY > trees[i].getYPos() && cursorY < (trees[i].getYPos() + trees[i].getHeight())){
                // printf("Cursor is over tree: %s\n", trees[i].getId());
                std::cout << "Cursor is over tree: " << trees[i].getID() << std::endl;
                std::cout << "Type of entity: " << trees[i].getType() << std::endl;
                setMouseTarget(trees[i].getID());
                Selector s(trees[i]);
                setSelector(s);
            } else {
                Selector s;
                setSelector(s);
            }
        }
    }
}

Entity Game::returnCursorTargetEntity(){
    Entity e;
        for (int i = 0; i < TREES_TO_SPAWN; i++){
        if (cursorX > trees[i].getXPos() && cursorX < (trees[i].getXPos() + trees[i].getWidth())){
            if (cursorY > trees[i].getYPos() && cursorY < (trees[i].getYPos() + trees[i].getHeight())){
                return trees[i];
            }
        }
    }
    return e;
}

void Game::drawSelector(sf::RenderWindow& window){
    selector.drawSelector(window);
}