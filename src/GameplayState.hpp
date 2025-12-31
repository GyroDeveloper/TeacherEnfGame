#ifndef GAMEPLAYSTATE_HPP
#define GAMEPLAYSTATE_HPP

//Libraries
#include "Commons.hpp"
#include "State.hpp"
#include "MathTeacher.hpp"
#include "Game.hpp"

//Classes
class GameplayState : public State{
    private:
        MathTeacher teacher;

    public:
        //Constructors && Destructors
        GameplayState(Game* game);

        //Methods
        void handleInput(sf::Event& event) override;
        void update(double dt) override;
        void draw(sf::RenderWindow& window, bool debug) override;

};

#endif
