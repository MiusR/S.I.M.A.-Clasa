#pragma once

#include "system.h"
#include <raylib.h>
#include "camera_component.h"
#include "data_transfer_component.h"
#include "model_component.h"
#include "physics_component.h"
#include "camera_component.h"
#include "position_component.h"
#include "texture_registry.h"

class ClickSimulationSystem : public System {
public:

    Actor* user;

    ClickSimulationSystem(Actor* user) {
        this->user = user;
        requirements.push_back(typeid(ModelComponent).name());
        requirements.push_back(typeid(PhysicsComponent).name());
        requirements.push_back(typeid(PositionComponent).name());
    }

    void doLogic(std::vector<Actor*> actors, int current) override;

};
