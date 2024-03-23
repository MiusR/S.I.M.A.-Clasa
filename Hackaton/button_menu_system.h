#pragma once
#include "system.h"
#include "system_manager.h"
#include "position_component.h"
#include "menu_button.h"
#include "texture_registry.h"
#include "sprite_component.h"

class ButtonMenuSystem : public System
{
public:
	ButtonMenuSystem() {
		requirements.push_back(typeid(PositionComponent).name());
		requirements.push_back(typeid(MenuButtonComponent).name());
		requirements.push_back(typeid(SpriteComponent).name());
	}

	void doLogic(std::vector<Actor*> actors, int current) override;
};


