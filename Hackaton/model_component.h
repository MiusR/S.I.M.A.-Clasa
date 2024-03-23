#pragma once

#include "component.h"
#include <raylib.h>

class ModelComponent : public Component {
public:

	Model model;
	Texture2D texture;
	float radius;

	ModelComponent(Model model, Texture2D texture) {
		this->model = model;
		this->texture = texture;

		BoundingBox bb = GetModelBoundingBox(model);

		this->radius = bb.max.x - bb.min.x;
		std::cout << radius << "\n\n\n\n\n";
		model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
	}

/*	~ModelComponent() {
		UnloadShader(model.materials[0].shader);
		UnloadTexture(model.materials[0].maps[MATERIAL_MAP_CUBEMAP].texture);
		UnloadModel(model);
	}*/
};