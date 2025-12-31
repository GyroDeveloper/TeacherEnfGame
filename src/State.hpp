#ifndef STATE_HPP
#define STATE_HPP

//Libraries
#include "Commons.hpp"

//Foward declaration
class Game;

//Classes
class State{ //Abstract
    protected:
        Game* game;

    public:
        //Constructors && Destructors
        State(Game* game);
        virtual ~State();

        //Methods
        virtual void handleInput(sf::Event& event) = 0;
        virtual void update(double secondsDt) = 0;
        virtual void draw(sf::RenderWindow& window, bool debug) = 0;
        
};

#endif