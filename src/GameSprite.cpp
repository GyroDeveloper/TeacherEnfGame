#include "GameSprite.hpp"

//Constructor && Destructor
GameSprite::GameSprite():
customHitbox(false){
    this->hitbox.setFillColor(sf::Color::Transparent);
    this->hitbox.setOutlineColor(sf::Color::Red);
    this->hitbox.setOutlineThickness(2.0f);
}

//Methods
bool GameSprite::load(std::string spriteDir){
    if(!this->texture.loadFromFile(spriteDir)){
        return false;
    }
    this->texture.setSmooth(true); //Bilinear Filter
    this->sprite.setTexture(this->texture);
    return true;
}

void GameSprite::draw(sf::RenderWindow& window, bool debug){
    window.draw(this->sprite);
    if(debug && this->customHitbox){
        window.draw(this->hitbox);
    }
    return;
}

void GameSprite::setPosition(float x, float y){
    this->sprite.setPosition(x, y);
    this->hitbox.setPosition(x, y);
    return;
}

sf::FloatRect GameSprite::getBounds() const{
    if(customHitbox){
        return this->hitbox.getGlobalBounds();
    }else{
        return this->sprite.getGlobalBounds();
    }
}

void GameSprite::setHitbox(float width, float height, float offsetX, float offsetY){
    this->hitbox.setSize(sf::Vector2f(width, height));
    this->hitbox.setOrigin(-offsetX, -offsetY);
    this->customHitbox = true;
}

bool GameSprite::isClicked(sf::Vector2f mousePos) const{
    if(this->customHitbox){
        return this->hitbox.getGlobalBounds().contains(mousePos);
    }else{
        return this->sprite.getGlobalBounds().contains(mousePos);
    }
}