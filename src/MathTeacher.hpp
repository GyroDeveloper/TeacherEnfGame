#ifndef MATHTEACHER_HPP
#define MATHTEACHER_HPP

//Libraries
#include "Commons.hpp"
#include "BaseTeacher.hpp"

//Classes
class MathTeacher : public BaseTeacher{
    public:
        //Constructor && Destructor
        MathTeacher();
        MathTeacher(float anger, float embarassament, ClothState clothState);
        ~MathTeacher();

        //Methods
        void update(double secondsDt) override;
};

#endif