#ifndef GAMESPRITE_HPP
#define GAMESPRITE_HPP

#include "Commons.hpp"

class GameSprite{
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::RectangleShape hitbox;
        bool customHitbox;
    
    public:
        GameSprite();
        bool load(std::string spriteDir);
        void draw(sf::RenderWindow& window, bool debug);
        void setPosition(float x, float y);
        sf::FloatRect getBounds() const;
        void setHitbox(float width, float height, float offsetX, float offsetY);
        bool isClicked(sf::Vector2f mousePos) const;

};

#endif