#include "GameplayState.hpp"

//Constructors && Destructors
GameplayState::GameplayState(Game* game):
State(game),
teacher(){}

//Methods
void GameplayState::handleInput(sf::Event& event){
    sf::Vector2i pixelPos;
    sf::Vector2f worldPos;
    sf::RenderWindow& window = this->game->getWindow();

    if(event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button == sf::Mouse::Left){
            pixelPos = sf::Mouse::getPosition(window);
            worldPos = window.mapPixelToCoords(pixelPos);
            this->teacher.tryClick(worldPos);
        }
    }
    return;
}

void GameplayState::update(double secondDt){
    //Does nothing right now
    return;
}

void GameplayState::draw(sf::RenderWindow& window, bool debug){
    window.clear();
    this->teacher.draw(window, debug);
    window.display();
    return;
}