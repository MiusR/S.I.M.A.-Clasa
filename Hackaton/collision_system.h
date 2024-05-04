#pragma once
#include "system.h"
#include "physics_component.h"
#include "position_component.h"
#include "model_component.h"
#include "util.h"

class CollisionSystem : public System {
public:

	CollisionSystem() {
		requirements.push_back(typeid(PositionComponent).name());
		requirements.push_back(typeid(PhysicsComponent).name());
		requirements.push_back(typeid(ModelComponent).name());
	}



	void Update() override;
};