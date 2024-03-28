#pragma once

#include <raylib.h>
#include "component.h"

class CameraComponent : public Component {

public:
	Camera camera;
	Vector3 initial_position;
	Vector3 initial_target;

	CameraComponent(Vector3 position, Vector3 target, float fov) {
		camera = { 0 };
		camera.position = position;
		initial_position = position;
		camera.target = target;
		initial_target = target;
		camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
		camera.fovy = fov;
		camera.projection = CAMERA_PERSPECTIVE;
	}
};