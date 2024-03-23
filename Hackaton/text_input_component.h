#pragma once

#include <raylib.h>
#include "component.h"
#include <functional>
#include "actor.h"

class TextuInputComponent : public Component
{
public:

    bool mark_writing = false;
    bool updated = true;
    std::string org;

    std::function<void(std::string string)> onEnter;

    // Marcator
    TextuInputComponent(std::function<void(std::string string)> onEnter, std::string org) {
        this->onEnter = onEnter;
        this->org = org;
    };

};
