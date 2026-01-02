#include "DebugTools.hpp"

//Methods
void DebugTools::ShowSpriteEditor(const std::string& label, GameSprite& sprite){
    sf::Vector2f pos, scale, hitboxSize, hitboxOrigin;
    float p[2], s[2], hs[2], ho[2];
    bool changed;
    std::string code;
    ImGui::Begin((label + " Properties").c_str());

    // 1-Position
    pos = sprite.getPosition();
    p[0] = pos.x; p[1] = pos.y;
    if((ImGui::DragFloat2("Position (X, Y)", p))){
        sprite.setPosition(p[0], p[1]);
    }

    // 2-Scale
    scale = sprite.getScale();
    s[0] = scale.x; s[1] = scale.y;
    if(ImGui::DragFloat2("Scale (X, Y)", s, 0.01f)){
        sprite.setScale(s[0], s[1]);
    }

    ImGui::Separator();
    ImGui::Text("Hitbox Settings");

    // 3-Hitbox
    hitboxSize = sprite.getHitboxSize();
    hitboxOrigin = sprite.getHitboxOrigin();
    hs[0] = hitboxSize.x ; hs[1] = hitboxSize.y;
    ho[0] = -hitboxOrigin.x ; ho[1] = -hitboxOrigin.y;
    changed = false;
    changed |= ImGui::DragFloat2("Size (W, H)", hs);
    changed |= ImGui::DragFloat2("Offset (X, Y)", ho);
    if(changed){
        sprite.setHitbox(hs[0], hs[1], ho[0], ho[1]);
    }

    ImGui::Separator();

    // 4-Code Generator
    if(ImGui::Button("Copy Code to Clipboard")){
        code = label + "\n";
        code += "sprite.setPosition(" + std::to_string(p[0]) + "f, " + std::to_string(p[1]) + "f);\n";
        code += "sprite.setHitbox(" + std::to_string(hs[0]) + "f, " + std::to_string(hs[1]) + "f, " 
            + std::to_string(ho[0]) + "f, " + std::to_string(ho[1]) + "f);";
        ImGui::SetClipboardText(code.c_str());
    }
    ImGui::End();
    return;
}