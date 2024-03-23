#pragma once

#include "system.h"
#include "position_component.h"
#include "rotate_around_axis_component.h"

class SpinActorSystem :public System
{
public:
	SpinActorSystem() {
		requirements.push_back(typeid(PositionComponent).name());
		requirements.push_back(typeid(RotateAroundAxisComponent).name());
	}
	void doLogic(std::vector<Actor*> actors, int current) override;
};