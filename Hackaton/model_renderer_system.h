#pragma once

#include "system.h"
#include "model_component.h"
#include <raylib.h>
#include "position_component.h"
#include "texture_registry.h"

class ModelRendererSystem : public System {
public:

	Camera* player;
	
	ModelRendererSystem(Camera* player) {
		requirements.push_back(typeid(PositionComponent).name());
		requirements.push_back(typeid(ModelComponent).name());
		this->player = player;
	}

	void doLogic(std::vector<Actor*> actors, int current) override;

	void Update() override;

};