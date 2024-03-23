#pragma once

#include "component.h"
#include <raylib.h>

class SpriteComponent : public Component {
public:
	Texture2D texture;

	int z_order = 0;

	SpriteComponent(Texture2D texture, int z_order) {
		this->texture = texture;
		this->z_order = z_order;
	}

	~SpriteComponent() {
		UnloadTexture(texture);
	}
};