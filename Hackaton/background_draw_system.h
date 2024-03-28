#pragma once

#include "system.h"
#include "position_component.h"
#include "sprite_component.h"
#include "background_component.h"

class BackgroundDrawSystem :public System
{
public:

	BackgroundDrawSystem() {
		requirements.push_back(typeid(SpriteComponent).name());
		requirements.push_back(typeid(BackgroundComponent).name());
		
	}


	void doLogic(std::vector<Actor*> actors, int current) override;

	void Update() override;
};