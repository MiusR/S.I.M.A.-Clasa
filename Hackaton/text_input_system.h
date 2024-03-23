#pragma once

#include "system.h"
#include "menu_button.h"
#include "text_input_component.h"

class TextInputSystem :public System
{
public:


    TextInputSystem() {
        requirements.push_back(typeid(MenuButtonComponent).name());
        requirements.push_back(typeid(TextuInputComponent).name());
    }


    void doLogic(std::vector<Actor*> actors, int current) override;

};
