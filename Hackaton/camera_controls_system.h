#pragma once

#include "system.h"
#include "camera_component.h"
#include <raylib.h>
#include "util.h"
#include <raymath.h>

class CameraControlsSystem :public System
{
public:

	const float turn_speed = 3;

	CameraControlsSystem() {
		requirements.push_back(typeid(CameraComponent).name());
	}


	void doLogic(std::vector<Actor*> actors, int current) override;

}; 
