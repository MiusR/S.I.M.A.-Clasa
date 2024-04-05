#pragma once
#include "system.h"
#include "system_manager.h"
#include "position_component.h"
#include "label_component.h"
#include "texture_registry.h"
#include "sprite_component.h"

class LabelDrawSystem : public System
{
public:
	LabelDrawSystem() {
		requirements.push_back(typeid(PositionComponent).name());
		requirements.push_back(typeid(LabelComponent).name());
		requirements.push_back(typeid(SpriteComponent).name());
	}

	void doLogic(std::vector<Actor*> actors, int current) override;
};


