#pragma once

#include "system.h"
#include "model_component.h"
#include <raylib.h>
#include "position_component.h"
#include "texture_registry.h"
#include "camera_component.h"
#include "raymath.h"
#include "util.h"

class SpawnPlanetsSystem : public System {
public:

	bool isSpawning = false;

	SpawnPlanetsSystem(){
		requirements.push_back(typeid(CameraComponent).name());
	}

	void doLogic(std::vector<Actor*> actors, int current) override;
};