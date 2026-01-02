#ifndef DEBUGTOOLS_HPP
#define DEBUGTOOLS_HPP

//Libraries
#include "Commons.hpp"
#include "GameSprite.hpp"

//Classes
class DebugTools{
    public:
        //Methods
        static void ShowSpriteEditor(const std::string& label, GameSprite& sprite);
};

#endif