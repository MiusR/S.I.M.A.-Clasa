#pragma once
#include "position_component.h"
#include "menu_button.h"
#include "actor.h"
#include "system_manager.h"
#include "sprite_component.h"
#include "texture_registry.h"
#include "data_transfer_component.h"
#include "text_input_component.h"
#include "physics_component.h"
#include "label_component.h"

inline Actor* CreateButton(float x, float y, float width, float height, std::string text, std::string texture, std::function<void(Actor*, std::vector<Actor*>)> lambda)
{
    PositionComponent* component = new PositionComponent(Vector3{ x,y,0 }, Vector3{ width, height, 0 });

    MenuButtonComponent* menuButton = new MenuButtonComponent(text, texture, width * height / 500, lambda);

    SpriteComponent* sprite = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture(texture.c_str()), 2);

    Actor* actor = new Actor();

    actor->AddComponent(component);
    actor->AddComponent(menuButton);
    actor->AddComponent(sprite);

    SystemManager::getInstance()->AddActor(actor);

    return actor;
}

inline Actor* CreateButton(float x, float y, float width, float height, int font_size, std::string text, std::string texture, std::function<void(Actor*, std::vector<Actor*>)> lambda)
{
    PositionComponent* component = new PositionComponent(Vector3{ x,y,0 }, Vector3{ width, height, 0 });

    MenuButtonComponent* menuButton = new MenuButtonComponent(text, texture, font_size, lambda);

    SpriteComponent* sprite = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture(texture.c_str()), 2);

    Actor* actor = new Actor();

    actor->AddComponent(component);
    actor->AddComponent(menuButton);
    actor->AddComponent(sprite);

    SystemManager::getInstance()->AddActor(actor);

    return actor;
}

inline Actor* CreateLabel(float x, float y, float width, float height, int font_size, std::string text, Color color) {
    PositionComponent* component = new PositionComponent(Vector3{ x,y,0 }, Vector3{ width, height, 0 });
    
    //ImageDrawText(&texture, text.c_str(), 0, 0, font_size, WHITE); // Draw text (custom sprite font) within an image (destination)
    
    SpriteComponent* sprite = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture("info"), 1);
    
    LabelComponent* label = new LabelComponent(text, font_size, color);

    Actor* actor = new Actor();

    actor->AddComponent(component);
    actor->AddComponent(sprite);
    actor->AddComponent(label);

    SystemManager::getInstance()->AddActor(actor);

    return actor;
}

inline Actor* CreateTextInput(float x, float y, float width, float heigth, std::string org, std::function<void(std::string)> fct) {
    Actor* actor = new Actor();

    TextuInputComponent* txt_input = new TextuInputComponent(fct, org);

    MenuButtonComponent* but_cmp = new MenuButtonComponent(org, "button", 20, [](Actor* actor, std::vector<Actor*> actors) {
        for (int i = 0; i < actors.size(); i++) {
            TextuInputComponent* comp = actors[i]->GetComponent<TextuInputComponent>();
            if (comp != nullptr)
                comp->mark_writing = false;
        }

        actor->GetComponent<TextuInputComponent>()->mark_writing = true;
        actor->GetComponent<MenuButtonComponent>()->text = "";
        });

    PositionComponent* pzt = new PositionComponent(Vector3{ x,y,0 }, Vector3{ width, heigth, 0 });

    SpriteComponent* sprt = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture("button"), 2);

    actor->AddComponent(txt_input);
    actor->AddComponent(but_cmp);
    actor->AddComponent(pzt);
    actor->AddComponent(sprt);

    SystemManager::getInstance()->AddActor(actor);

    return actor;
}