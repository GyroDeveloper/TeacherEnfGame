#include "Game.hpp"

//Constructor
Game::Game(): 
window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE),
teacher(){
    this->window.setFramerateLimit(MAX_FRAMERATE);
}

//Private Methods
void Game::processEvents() {
    sf::Event event;
    sf::Vector2i pixelPos;
    sf::Vector2f worldPos;

    while(this->window.pollEvent(event)){
        if (event.type == sf::Event::Closed){
            this->window.close();
        }

        if(event.type == sf::Event::MouseButtonPressed){
            if(event.mouseButton.button == sf::Mouse::Left){
                pixelPos = sf::Mouse::getPosition(this->window);
                worldPos = this->window.mapPixelToCoords(pixelPos);
                this->teacher.tryClick(worldPos);
            }
        }
    }
}

void Game::update(double secondsDt) {
    // Mock behavior, just for testing
    //std::cout << "Seconds: " << secondsDt << "\n";
}

void Game::render(bool debug) {
    this->window.clear();
    this->teacher.draw(this->window, debug);
    this->window.display();
}

void Game::run(bool debug) {
    sf::Clock clock;
    
    while(this->window.isOpen()){
        sf::Time dtTime = clock.restart();
        double secondsDt = dtTime.asSeconds();

        // Game Loop
        this->processEvents();
        this->update(secondsDt);
        this->render(debug);
    }
}