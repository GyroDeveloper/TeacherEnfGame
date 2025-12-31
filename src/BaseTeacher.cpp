#include "BaseTeacher.hpp"

//Constructor && Destructor
BaseTeacher::BaseTeacher():
anger(0.0f),
embarassament(0.0f),
clothState(ClothState::DRESSED){}

BaseTeacher::BaseTeacher(float anger, float embarassament, ClothState clothState):
BaseTeacher::BaseTeacher(){
    this->setAnger(anger);
    this->setEmbarassament(embarassament);
    this->setClothState(clothState);
}

BaseTeacher::~BaseTeacher(){};

//Getters && Setters
float BaseTeacher::getAnger() const{
    return this->anger;
}

float BaseTeacher::getEmbarassament() const{
    return this->embarassament;
}

const ClothState BaseTeacher::getClothState() const{
    return this->clothState;
}

bool BaseTeacher::setAnger(float anger){
    if(anger >= 0){
        this->anger = anger;
        return true;
    }
    return false;
}

bool BaseTeacher::setEmbarassament(float embarassament){
    if(embarassament >= 0){
        this->embarassament = embarassament;
        return true;
    }
    return false;
}

bool BaseTeacher::setClothState(ClothState clothState){
    this->clothState = clothState;
    return true;
}

//Methods
void BaseTeacher::draw(sf::RenderWindow& window, bool debug){
    this->sprites[this->clothState].draw(window, debug);
    return;
}

bool BaseTeacher::tryClick(sf::Vector2f mousePos){
    if(this->sprites.at(this->clothState).isClicked(mousePos)){
        if(this->clothState == ClothState::DRESSED){
            this->clothState = ClothState::UNDERWEAR;
        }else if(this->clothState == ClothState::UNDERWEAR){
            this->clothState = ClothState::NAKED;
        }else{ 
            this->clothState = ClothState::DRESSED;
        }
        return true;
    }
    return false;
}