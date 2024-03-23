#pragma once
#include <raylib.h>
#include "component.h"
#include <functional>
#include "actor.h"

class MenuButtonComponent : public Component
{
public:

    std::function<void(Actor*, std::vector<Actor*>)> onClick;

    std::string text;

    std::string texture, hover_texture;

    int font_size;


    MenuButtonComponent(std::string text, std::string texture, int font_size, std::function<void(Actor*, std::vector<Actor*>) > lambda)
    {
        this->onClick = lambda;
        this->text = text;
        this->texture = texture;
        this->hover_texture = texture + "_pressed";
        this->font_size = font_size;
    }

    MenuButtonComponent(std::string text, std::string texture, std::string hover_texture, int font_size, std::function<void(Actor*, std::vector<Actor*>)> lambda)
    {
        this->onClick = lambda;
        this->text = text;
        this->texture = texture;
        this->hover_texture = hover_texture;
        this->font_size = font_size;
    }

};