#pragma once
#include "system.h"
#include "physics_component.h"
#include "position_component.h"
#include "util.h"

class LearningPhysicsSystem : public System {
public:

	//const float G = 6.67 * (1 / 100000000000); //aici pc-ul incepe sa planga :( (gata smecheria) sa dus

	LearningPhysicsSystem() {
		requirements.push_back(typeid(PositionComponent).name());
		requirements.push_back(typeid(PhysicsComponent).name());
	}



	void doLogic(std::vector<Actor*> actors, int current) override;
};
