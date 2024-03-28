#pragma once

#include "system.h"
#include "util.h"
#include "camera_component.h"
#include "data_transfer_component.h"
#include "model_component.h"
#include "physics_component.h"
#include "camera_component.h"
#include "position_component.h"
#include "texture_registry.h"
#include "ui_util.h"

class FocusSystem : public System {
public:

    bool isShowingInfo = false;

    Actor* info_actor;

    FocusSystem() {
        requirements.push_back(typeid(DataTransferComponent).name());
        requirements.push_back(typeid(CameraComponent).name());
    }

    void doLogic(std::vector<Actor*> actors, int current) override;
};
