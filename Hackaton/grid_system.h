#pragma once

#include "system.h"
#include "model_component.h"
#include <raylib.h>
#include "position_component.h"
#include "texture_registry.h"
#include "camera_component.h"

class GridSystem : public System {
public:

	GridSystem() {
		requirements.push_back(typeid(CameraComponent).name());
	}

	void doLogic(std::vector<Actor*> actors, int current) override;

};