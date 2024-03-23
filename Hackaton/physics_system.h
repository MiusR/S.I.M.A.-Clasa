#pragma once
#include "system.h"
#include "physics_component.h"
#include "position_component.h"
#include "model_component.h"
#include "util.h"

class PhysicsSystem : public System {
public:

	//const float G = 6.67 * (1 / 100000000000); //aici pc-ul incepe sa planga :( (gata smecheria) sa dus

	PhysicsSystem() {
		requirements.push_back(typeid(PositionComponent).name());
		requirements.push_back(typeid(PhysicsComponent).name());
		requirements.push_back(typeid(ModelComponent).name());
	}



	void doLogic(std::vector<Actor*> actors, int current) override;
};