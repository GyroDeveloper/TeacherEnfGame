#ifndef GAME_HPP
#define GAME_HPP

//Libraries
#include "Commons.hpp"
#include "MathTeacher.hpp"

//Classes
class Game{
    private:
        sf::RenderWindow window;
        MathTeacher teacher;

        void processEvents();
        void update(double secondsDt);
        void render(bool debug);

    public:
        Game();
        void run(bool debug);
};

#endif