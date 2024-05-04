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

	Font base_font;

	LabelDrawSystem() {
		requirements.push_back(typeid(PositionComponent).name());
		requirements.push_back(typeid(LabelComponent).name());
		requirements.push_back(typeid(SpriteComponent).name());
		base_font = LoadFont("pixelplay.png");
	}

	void doLogic(std::vector<Actor*> actors, int current) override;
};


