#pragma once
#include <raylib.h>
#include "component.h"

class RotateAroundAxisComponent : public Component {

public:
	float angle;

	RotateAroundAxisComponent(float angle) {
		this->angle = angle;
	}
};
