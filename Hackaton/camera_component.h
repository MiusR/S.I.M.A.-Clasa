#pragma once

#include <raylib.h>
#include "component.h"

class CameraComponent : public Component {

public:
	Camera camera;

	CameraComponent(Vector3 position, Vector3 target, float fov) {
		camera = { 0 };
		camera.position = position;
		camera.target = target;
		camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
		camera.fovy = fov;
		camera.projection = CAMERA_PERSPECTIVE;
	}
};