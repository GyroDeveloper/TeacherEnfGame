#include "MathTeacher.hpp"

//Constructor && Destructor
MathTeacher::MathTeacher():
BaseTeacher(){
    if(!this->sprites[ClothState::DRESSED].load(ASSETS_DIR + "sprites/TeacherTest/Undress02.png")){
        std::cerr << "Erro ao carregar sprite DRESSED!\n";
    }
    if(!this->sprites[ClothState::UNDERWEAR].load(ASSETS_DIR + "sprites/TeacherTest/Undress01.png")){
        std::cerr << "Erro ao carregar sprite UNDERWEAR!\n";
    }
    if(!this->sprites[ClothState::NAKED].load(ASSETS_DIR + "sprites/TeacherTest/Undress00.png")){
        std::cerr << "Erro ao carregar sprite NAKED!\n";
    }
}

MathTeacher::MathTeacher(float anger, float embarassament, ClothState clothState):
BaseTeacher(anger, embarassament, clothState){}

MathTeacher::~MathTeacher(){}

//Methods
void MathTeacher::update(double secondsDt){
    std::cout << secondsDt << "\n";
    return;
}

