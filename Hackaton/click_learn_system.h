#pragma once

#include "system.h"
#include <raylib.h>
#include "camera_component.h"
#include "data_transfer_component.h"
#include "model_component.h"
#include "physics_component.h"
#include "camera_component.h"
#include "position_component.h"

class ClickLearnSystem : public System {
public:

    Actor* user;

    ClickLearnSystem(Actor* user) {
        this->user = user;
        requirements.push_back(typeid(ModelComponent).name());
        requirements.push_back(typeid(PositionComponent).name());
    }

    void doLogic(std::vector<Actor*> actors, int current) override;

};
