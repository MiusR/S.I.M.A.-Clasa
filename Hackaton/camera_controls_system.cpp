#include "camera_controls_system.h"

void CameraControlsSystem::doLogic(std::vector<Actor*> actors, int current) {
	CameraComponent* camera = actors[current]->GetComponent<CameraComponent>();

	if (IsKeyDown(65)) {
		Matrix rotation = MatrixRotate({0, 1, 0}, turn_speed * GetFrameTime());
		Vector3 view = Vector3Subtract(camera->camera.position, camera->camera.target);
		view = Vector3Transform(view, rotation);
		camera->camera.position = Vector3Add(camera->camera.target, view);
	}
	else if (IsKeyDown(68)) {
		Matrix rotation = MatrixRotate({ 0, 1, 0 }, -turn_speed * GetFrameTime());
		Vector3 view = Vector3Subtract(camera->camera.position, camera->camera.target);
		view = Vector3Transform(view, rotation);
		camera->camera.position = Vector3Add(camera->camera.target, view);
	}




	if (GetMouseWheelMove() != 0 || IsKeyDown(87) || IsKeyDown(83)) {
		Vector3 move_vector = Vector3Subtract(camera->camera.target, camera->camera.position);
		
		int sign = ((GetMouseWheelMove() < 0) ? -1 : 1);

		if (IsKeyDown(83)) {
			sign = -sign;
		}

		camera->camera.position = Vector3Add(camera->camera.position, toScalarVector(move_vector, sign * GetFrameTime()));
	}
}

