#ifndef BASETEACHER_HPP
#define BASETEACHER_HPP

//Libraries
#include "Commons.hpp"
#include "GameSprite.hpp"

//Classes
enum class ClothState{
    DRESSED,
    UNDERWEAR,
    NAKED
};

class BaseTeacher{
    protected:
        float anger, embarassament;
        ClothState clothState;
        std::map<ClothState, GameSprite> sprites;

    public:
        //Constructor && Destructor
        BaseTeacher();
        BaseTeacher(float anger, float embarassament, ClothState clothState);
        virtual ~BaseTeacher();

        //Getters && Setters
        float getAnger() const;
        float getEmbarassament() const;
        const ClothState getClothState() const;
        bool setAnger(float anger);
        bool setEmbarassament(float embarassament);
        bool setClothState(ClothState clothState);

        //Methods
        virtual void update(double secondsDt) = 0;
        void draw(sf::RenderWindow& window, bool debug);
        bool tryClick(sf::Vector2f mousePos);
};

#endif